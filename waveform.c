#include "waveform.h"
#include <math.h>

// Phase A   ------------------------------------------------------
//RMS (A)
double calculate_phase_A_rms(WaveformSample *data, int num_samples) {
    double sum_of_squares = 0.0;

    for (int i = 0; i < num_samples; i++) {
        double voltage = data[i].phase_A_voltage;
        sum_of_squares += (voltage * voltage);
    }

    double mean_of_squares = sum_of_squares / num_samples;

    return sqrt(mean_of_squares);
}
//P2P (A)
double calculate_phase_A_peak_to_peak(WaveformSample *dataset, int row_count) {
    double max_val = dataset[0].phase_A_voltage;
    double min_val = dataset[0].phase_A_voltage;

    for (int i = 1; i < row_count; i++) {
        double current_voltage = dataset[i].phase_A_voltage;

        if (current_voltage > max_val) {max_val = current_voltage;}
        if (current_voltage < min_val) {min_val = current_voltage;}
    }
    return max_val - min_val;
}
//DC Offset (A)
double calculate_phase_A_dc_offset(WaveformSample *dataset, int row_count) {
    double total_sum = 0.0;

    for (int i = 0; i < row_count; i++) {
        total_sum += dataset[i].phase_A_voltage;
    }

    double dc_offset = total_sum / row_count;
    return dc_offset;
}
//Clipping (A)
int count_phase_A_clipping(WaveformSample *dataset, int row_count) {
    int clip_count = 0;

    for (int i = 0; i < row_count; i++) {
        double absolute_voltage = fabs(dataset[i].phase_A_voltage);

        if (absolute_voltage >= 324.9) {
            clip_count++;
        }
    }
    return clip_count;
}
// Phase B   ------------------------------------------------------
//RMS (B)
double calculate_phase_B_rms(WaveformSample *dataset, int row_count) {
    double sum_sq = 0.0;
    for (int i = 0; i < row_count; i++) {
        double v = dataset[i].phase_B_voltage;
        sum_sq += (v * v);
    }
    return sqrt(sum_sq / row_count);
}
//P2P (B)
double calculate_phase_B_peak_to_peak(WaveformSample *dataset, int row_count) {
    double max_val = dataset[0].phase_B_voltage;
    double min_val = dataset[0].phase_B_voltage;
    for (int i = 1; i < row_count; i++) {
        if (dataset[i].phase_B_voltage > max_val) max_val = dataset[i].phase_B_voltage;
        if (dataset[i].phase_B_voltage < min_val) min_val = dataset[i].phase_B_voltage;
    }
    return max_val - min_val;
}
//DC Offset (B)
double calculate_phase_B_dc_offset(WaveformSample *dataset, int row_count) {
    double total_sum = 0.0;

    for (int i = 0; i < row_count; i++) {
        total_sum += dataset[i].phase_B_voltage;
    }

    double dc_offset = total_sum / row_count;

    return dc_offset;
}
//Clipping (B)
int count_phase_B_clipping(WaveformSample *dataset, int row_count) {
    int clip_count = 0;

    for (int i = 0; i < row_count; i++) {
        double absolute_voltage = fabs(dataset[i].phase_B_voltage);

        if (absolute_voltage >= 324.9) {
            clip_count++;
        }
    }
    return clip_count;
}

// Phase C   ------------------------------------------------------
//RMS (C)
double calculate_phase_C_rms(WaveformSample *dataset, int row_count) {
    double sum_sq = 0.0;
    for (int i = 0; i < row_count; i++) {
        double v = dataset[i].phase_C_voltage;
        sum_sq += (v * v);
    }
    return sqrt(sum_sq / row_count);
}
//P2P (C)
double calculate_phase_C_peak_to_peak(WaveformSample *dataset, int row_count) {
    double max_val = dataset[0].phase_C_voltage;
    double min_val = dataset[0].phase_C_voltage;
    for (int i = 1; i < row_count; i++) {
        if (dataset[i].phase_C_voltage > max_val) max_val = dataset[i].phase_C_voltage;
        if (dataset[i].phase_C_voltage < min_val) min_val = dataset[i].phase_C_voltage;
    }
    return max_val - min_val;
}
//DC Offset (C)
double calculate_phase_C_dc_offset(WaveformSample *dataset, int row_count) {
    double total_sum = 0.0;

    for (int i = 0; i < row_count; i++) {
        total_sum += dataset[i].phase_C_voltage;
    }

    double dc_offset = total_sum / row_count;

    return dc_offset;
}
//Clipping (C)
int count_phase_C_clipping(WaveformSample *dataset, int row_count) {
    int clip_count = 0;

    for (int i = 0; i < row_count; i++) {
        double absolute_voltage = fabs(dataset[i].phase_C_voltage);

        if (absolute_voltage >= 324.9) {
            clip_count++;
        }
    }
    return clip_count;
}