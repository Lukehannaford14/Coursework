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

        // PHASE A RESULTS -----------------------------------------------------------------------
        printf("--- PHASE A ---\n");
        double phase_A_rms = calculate_phase_A_rms(dataset, row_count);
        printf("RMS: %.2f V\n", calculate_phase_A_rms(dataset, row_count));
        if (phase_A_rms >= 207.0 && phase_A_rms <= 253.0) {
            printf("Status: COMPLIANT\n");
        } else {
            printf("Status: WARNING - OUT OF TOLERANCE\n");
        }
        printf("P-P: %.2f V\n", calculate_phase_A_peak_to_peak(dataset, row_count));
        printf("DC Offset: %.2f V\n", calculate_phase_A_dc_offset(dataset, row_count));
        printf("Clipped: %d\n", count_phase_A_clipping(dataset, row_count));


        // PHASE B RESULTS ----------------------------------------------------------------------
        printf("\n--- PHASE B ---\n");
        double phase_B_rms = calculate_phase_B_rms(dataset, row_count);
        printf("RMS: %.2f V\n", calculate_phase_B_rms(dataset, row_count));
        if (phase_B_rms >= 207.0 && phase_B_rms <= 253.0) {
            printf("Status: COMPLIANT\n");
        } else {
            printf("Status: WARNING - OUT OF TOLERANCE\n");
        }
        printf("P-P: %.2f V\n", calculate_phase_B_peak_to_peak(dataset, row_count));
        printf("DC Offset: %.2f V\n", calculate_phase_B_dc_offset(dataset, row_count));
        printf("Clipped: %d\n", count_phase_B_clipping(dataset, row_count));

        // PHASE C RESULTS ---------------------------------------------------------------------
        printf("\n--- PHASE C ---\n");
        double phase_C_rms = calculate_phase_C_rms(dataset, row_count);
        printf("RMS: %.2f V\n", calculate_phase_C_rms(dataset, row_count));
        if (phase_C_rms >= 207.0 && phase_C_rms <= 253.0) {
            printf("Status: COMPLIANT\n");
        } else {
            printf("Status: WARNING - OUT OF TOLERANCE\n");
        }
        printf("P-P: %.2f V\n", calculate_phase_C_peak_to_peak(dataset, row_count));
        printf("DC Offset: %.2f V\n", calculate_phase_C_dc_offset(dataset, row_count));
        printf("Clipped: %d\n", count_phase_C_clipping(dataset, row_count));
    }
    else {
        printf("Error: Could not open file %s\n", argv[1]);
    }
    free(dataset);
    return 0;
}