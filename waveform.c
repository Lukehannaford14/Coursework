#include "waveform.h"
#include <math.h>

//RMS Start
double calculate_phase_A_rms(WaveformSample *data, int num_samples) {
    double sum_of_squares = 0.0;

    for (int i = 0; i < num_samples; i++) {
        double voltage = data[i].phase_A_voltage;
        sum_of_squares += (voltage * voltage);
    }

    double mean_of_squares = sum_of_squares / num_samples;

    return sqrt(mean_of_squares);
}
//RMS End

//Peak To Peak End
double calculate_phase_A_peak_to_peak(WaveformSample *dataset, int row_count) {
    double max_val = dataset[0].phase_A_voltage;
    double min_val = dataset[0].phase_A_voltage;

    for (int i = 1; i < row_count; i++) {
        double current_voltage = dataset[i].phase_A_voltage;

        if (current_voltage > max_val) {
            max_val = current_voltage;
        }

        if (current_voltage < min_val) {
            min_val = current_voltage;
        }
    }
    return max_val - min_val;
}
//Peak To Peak End

//DC Offset Start
double calculate_phase_A_dc_offset(WaveformSample *dataset, int row_count) {
    double total_sum = 0.0;

    for (int i = 0; i < row_count; i++) {
        total_sum += dataset[i].phase_A_voltage;
    }

    double dc_offset = total_sum / row_count;

    return dc_offset;
}
//Peak To Peak End
