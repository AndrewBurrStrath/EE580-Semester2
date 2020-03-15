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


float * applyIIR(float *x, float *y, int n, int lp, int bp, int hp) {
/* 	x = contents of buffer
	y = filtered buffer output 
	n = pointer to current sample
	lp is high when low pass filter is to be applied
	bp is high when band pass filter is to be applied
	hp is high when high pass filter is to be applied*/
	
	static int N = 0;	// Current length of filter a 
	static int M = 0;	// Current length of filter b

	int l = 0; int k = 0;

	y[n] = 0;
	
	//Convolution of y and a
	for (l = 1; l <= N; l++) {
		y[n] = y[n] + (lp*a_lp[l] + bp*a_bp[l] + hp*a_hp[l])*y[y-l];
	}
	
	//Convolution of x and b
	for (k = 0; k <= M; k++) {
		y[n] = y[n] + (lp*b_lp[l] + bp*b_bp[l] + hp*b_hp[l])*x[y-l];
	}
	
	//Only increase N and M if smaller than length of filter coefficients
	if(N < N_A)
		N++;
	if(M < N_B)
		M++;
	

	return convolution;
}
