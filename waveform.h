#ifndef UNTITLED_WAVEFORM_H
#define UNTITLED_WAVEFORM_H
#include <stdint.h>

// Waveform Sample
typedef struct {
    double timestamp;
    double phase_A_voltage;
    double phase_B_voltage;
    double phase_C_voltage;
    double line_current;
    double frequency;
    double power_factor;
    double thd_percent;
} WaveformSample;


// Phase A RMS
double calculate_phase_A_rms(WaveformSample *data, int num_samples);

// Phase A P2P
double calculate_phase_A_peak_to_peak(WaveformSample *dataset, int row_count);

// Phase A DC Offset
double calculate_phase_A_dc_offset(WaveformSample *dataset, int row_count);

#endif
