/*
 * main.c
 */
#include <stdio.h>
#include <math.h>

#include<string.h>
#include<stdlib.h>


//#pragma warning(disable:4996)


int main(void) {
	double x[24] = {0};

	FILE *stream;
	char* file;
	file = strdup(getenv("HOME"));
	file = "sinearray.txt";
	stream = fopen(file, "a");
	int i;

	if (stream == NULL)
	{
		printf("Could not locate sine array file\n");
		return 0;
	}

	int n = 0;
	for(n; n<24; n++){
		x[n] = sin(2*3.1415*(1 / 9.6)*n);
		fprintf(stream, "%f\n", x[n]);
	}

	fclose(stream);


	return 0;
}
