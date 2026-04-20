#ifndef UNTITLED_WAVEFORM_H
#define UNTITLED_WAVEFORM_H

#include <stdint.h>

typedef struct {
    double timestamp;
    double phase_A_voltage;
    double phase_B_voltage;
    double phase_C_voltage;
    double line_current;
    double power_factor;
    double thd_percent;
} WaveformSample;


#endif
