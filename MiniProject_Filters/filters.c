#include "stdio.h"
#include "types.h"
#include "evmc6748.h"
#include "evmc6748_timer.h"
#include "evmc6748_i2c.h"
#include "evmc6748_led.h"
#include "evmc6748_dip.h"

#include "filterCoefficients.h"

float * conv(float*, float*, int, int);

float * lowPassFilter(float *signal) {
	
	float filtered_signal[24000];
	float *p = filtered_signal;
	p = conv(signal, lowPassCoefficients, 24000, 125);

	return p;
}

float * bandPassFilter(float *signal) {
	
	float filtered_signal[24000];
	float *p = filtered_signal;
	p = conv(signal, bandPassCoefficients, 24000, 125);

	return p;
}

float * highPassFilter(float *signal) {
	
	float filtered_signal[24000];
	float *p = filtered_signal;
	p = conv(signal, highPassCoefficients, 24000, 125);

	return p;
}

float * conv(float *x, float *y, int length_x, int length_y) {
	//Convolves two signals, x and y
	const conv_len = length_x + length_y - 1;
	static float convolution[24000] = { 0 };

	int i = 0; int j = 0;
	for (i = 0; i < conv_len; i++) {
		for (j = i; (j >= 0) && (length_y - 1 - (i - j)>=0); j--) {
			if (j < length_x)
				convolution[i] = convolution[i] + x[j] * y[length_y - 1 - (i - j)];
		}
	}

	return convolution;
}