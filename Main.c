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
        printf("Data loaded successfully from %s\n", argv[1]);

        printf("First Phase A Voltage: %.2f V\n", dataset[0].phase_A_voltage);
    } else {
        printf("Error: Could not open file %s\n", argv[1]);
    }

    free(dataset);
    return 0;
}
