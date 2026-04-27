#include <stdio.h>
#include <stdlib.h>
#include "io.h"

int load_csv(const char *filename, WaveformSample *dataset, int row_count) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        return 0;
    }

    char buffer[1024];

    fgets(buffer, sizeof(buffer), file);


    for (int i = 0; i < row_count; i++) {
        if (fgets(buffer, sizeof(buffer), file)) {
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