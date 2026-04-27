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


// Phase A   ----------------------------------------------------
double calculate_phase_A_rms(WaveformSample *data, int num_samples);

double calculate_phase_A_peak_to_peak(WaveformSample *dataset, int row_count);

double calculate_phase_A_dc_offset(WaveformSample *dataset, int row_count);

int count_phase_A_clipping(WaveformSample *dataset, int row_count);

// Phase B   ----------------------------------------------------
double calculate_phase_B_rms(WaveformSample *dataset, int row_count);

double calculate_phase_B_peak_to_peak(WaveformSample *dataset, int row_count);

double calculate_phase_B_dc_offset(WaveformSample *dataset, int row_count);

int count_phase_B_clipping(WaveformSample *dataset, int row_count);

// Phase C   ----------------------------------------------------
double calculate_phase_C_rms(WaveformSample *dataset, int row_count);

double calculate_phase_C_peak_to_peak(WaveformSample *dataset, int row_count);

double calculate_phase_C_dc_offset(WaveformSample *dataset, int row_count);

int count_phase_C_clipping(WaveformSample *dataset, int row_count);

#endif