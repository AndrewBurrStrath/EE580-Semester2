int * conv(int *tap, int *x, int length){
	static int convolution[24] = {0};
	

	int i;
	for (i = 0; i < 20; i++) {
		printf("n[%d] = %d\n", i, x[i]);
	}

		int k = 0;int j = 0;
		for (k = length+3; k>=0; k--){
			for(j = 0; (j<=k && j < 5); j++){
				convolution[k] = convolution[k] + tap[j]*x[k-j];

			}
		}


		return convolution;
}
