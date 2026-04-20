#include <stdio.h>
#include <stdlib.h>
#include "io.h"

int load_csv(const char *filename, WaveformSample *dataset, int row_count) {
    FILE *file = fopen(filename, "r"); // Open file for reading

    if (file == NULL) {
        return 0; // Return 0 to signal "File Not Found"
    }

    char buffer[1024]; // A temporary "bucket" to hold one line of text

    // 1. Skip the header row
    fgets(buffer, sizeof(buffer), file);

    // 2. Loop through the rows [cite: 249, 250]
    for (int i = 0; i < row_count; i++) {
        if (fgets(buffer, sizeof(buffer), file)) {
            // sscanf looks for 8 doubles (%lf) separated by commas
            sscanf(buffer, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
                   &dataset[i].timestamp,
                   &dataset[i].phase_A_voltage,
                   &dataset[i].phase_B_voltage,
                   &dataset[i].phase_C_voltage,
                   &dataset[i].line_current,
                   &dataset[i].frequency,
                   &dataset[i].power_factor,
                   &dataset[i].thd_percent);
        }
    }

    fclose(file);
    return 1;
}
