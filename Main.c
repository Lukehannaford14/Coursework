#include <stdio.h>
#include <stdlib.h>
#include "waveform.h"
#include "io.h"

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <filename.csv>\n", argv[0]);
        return 1;
    }

    int row_count = 1000;
    WaveformSample *dataset = malloc(row_count * sizeof(WaveformSample));

    if (dataset == NULL) return 1;

    if (load_csv(argv[1], dataset, row_count)) {
        printf("Data loaded successfully from %s\n\n", argv[1]);

        //RMS Calc
        double phase_A_rms = calculate_phase_A_rms(dataset, row_count);

        printf("Phase A RMS Voltage: %.2f V\n", phase_A_rms);

        if (phase_A_rms >= 207.0 && phase_A_rms <= 253.0) {
            printf("Status: COMPLIANT\n");
        } else {
            printf("Status: WARNING - OUT OF TOLERANCE\n");
        }

        //Peak To Peak
        double phase_A_p2p = calculate_phase_A_peak_to_peak(dataset, row_count);
        printf("Phase A Peak-to-Peak Voltage: %.2f V\n", phase_A_p2p);

        //DC Offset
        double phase_A_dc = calculate_phase_A_dc_offset(dataset, row_count);
        printf("Phase A DC Offset: %.2f V\n", phase_A_dc);

    }
    else {
        printf("Error: Could not open file %s\n", argv[1]);
    }

    free(dataset);
    return 0;
}
