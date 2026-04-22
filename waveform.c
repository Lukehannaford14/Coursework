#include "waveform.h"
#include <math.h>
#include <stdio.h>

double compute_rms(WaveformSample *ptr, int n) {
    double sum_sq = 0.0;
    for (int i = 0; i < n; i++) {
        double v = (ptr + i)->phase_A_voltage;
        sum_sq += v * v;
    }
    return sqrt(sum_sq / n);
}

double compute_dc_offset(WaveformSample *ptr, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += (ptr + i)->phase_A_voltage;
    }
    return sum / n;
}

int count_clipped_samples(WaveformSample *ptr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        double v = (ptr + i)->phase_A_voltage;

        if (v >= 324.9 || v <= -324.9) {
            count++;
        }
    }
    return count;
}
