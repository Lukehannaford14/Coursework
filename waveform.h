#ifndef UNTITLED_WAVEFORM_H
#define UNTITLED_WAVEFORM_H

#include <stdint.h>

typedef struct {
    double timestamp;
    double phase_A_voltage;
    double phase_B_voltage;
    double phase_C_voltage;
    double frequency;
    double line_current;
    double power_factor;
    double thd_percent;
} WaveformSample;

double compute_rms(WaveformSample *ptr, int n);
double compute_dc_offset(WaveformSample *ptr, int n);
int count_clipped_samples(WaveformSample *ptr, int n);

#endif
