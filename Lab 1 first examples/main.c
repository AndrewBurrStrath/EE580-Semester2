/*
 * main.c
 */
#include <stdio.h>

//#pragma warning(disable:4996)


int * conv(int *tap, int *x, int length);

int main(void) {
	int tap[5] = {1, 0, 2, 0, 1};
	int x[20] = {0};
	int i;
	printf("Please enter an length of x\n");
	scanf("%d", &i);
	int j = 0;
	printf("Please enter coefficients:\n");
	for(j = 0; j<i; j++){
		scanf("%d", &(x[j]));
	}
	int arr[20];
	int *p = arr;
	p = conv(tap, x, i);

	//int c[24] = {0};
	//c = &p;
	/*int convolution[24] = {0};
	int k = 0;
	j = 0;
	int length = i;
	for (k = length+3; k>=0; k--){
		for(j = 0; (j<=k && j <= 5); j++){
			convolution[k] = convolution[k] + tap[j]*x[k-j];

		}
	}*/


	for (j=0; j<20; j++){
		printf("%d\n",*(p+j));
	}
	return 0;
}
