#include <stdio.h>	
#include <math.h>
#include <stdlib.h>

void convolve(float**,float,float,float**,float**,float**,float**,float**,float**);
void display(float**,float**,float**);

int main() {
	int kernel_size = 3;
	int arr_size = 9;
	float resultant_1[7][7];
	float resultant_2[7][7];
	float resultant_3[7][7];

	float** arr = (float**)malloc(9*sizeof(float*));
	for (int i=0; i<9; i++) {
		arr[i] = (float*)malloc(9*sizeof(float));
	}

	for (int i=0; i<9; i++) {
		for (int j=0; j<9; j++) {
			if( ((i == j) || (i+j == 8)) && ( i!=0 || i!=8 || j!=0 || j!=8)) arr[i][j] = 1;
			else arr[i][j] = -1;
		}
	}

//	arr = {
//		{-1, -1, -1, -1, -1, -1, -1, -1, -1},
//		{-1, 1, -1, -1, -1, -1, -1, 1, -1},
//		{-1, -1, 1, -1, -1, -1, 1, -1, -1},
//		{-1, -1, -1, 1, -1, 1, -1, -1, -1},
//		{-1, -1, -1, -1, 1, -1, -1, -1, -1},
//		{-1, -1, -1, 1, -1, 1, -1, -1, -1},
//		{-1, -1, 1, -1, -1, -1, 1, -1, -1},
//		{-1, 1, -1, -1, -1, -1, -1, 1, -1},
//		{-1, -1, -1, -1, -1, -1, -1, -1, -1}
//	};

	for (int i=0; i<9; i++) {
		for (int j=0; j<9; j++) {
			printf("%f, ", arr[i][j]);
		}
		printf("\n");
	}

	float kernel_1[3][3] = {
		{1, -1, -1},
		{-1, 1, -1},
		{-1, -1, 1}
	};

	float kernel_2[3][3] = {
		{1, -1, 1},
		{-1, 1, -1},
		{1, -1, 1}
	};
	
	float kernel_3[3][3] = {
		{-1, -1, 1},
		{-1, 1, -1},
		{1, -1, -1}
	};

	//convolve(arr, arr_size, kernel_size, kernel_1, kernel_2, kernel_3, resultant_1, resultant_2, resultant_3);

	//display(resultant_1, resultant_2, resultant_3);


	return 0;
}

void convolve(float** arr, float arr_size, float kernel_size, float** kernel_1, float** kernel_2, float** kernel_3, float** resultant_1, float** resultant_2, float** resultant_3) {
	float convolve_sum = 0;
	float convolve_average = 0;


	for (int j=0; j<=(arr_size - kernel_size); j++) {
		for (int i=0; i<=(arr_size - kernel_size); i++) {
			for (int m=0; m<kernel_size; m++) {
				for (int n=0; n<kernel_size; n++) {
					convolve_sum += kernel_1[m][n] * arr[i+m][j+n];
				}
			}
			convolve_average = convolve_sum / (kernel_size * kernel_size);
			resultant_1[i][j] = convolve_average;
		}
		convolve_sum = 0;
	}
	for (int j=0; j<=(arr_size - kernel_size); j++) {
		for (int i=0; i<=(arr_size - kernel_size); i++) {
			for (int m=0; m<kernel_size; m++) {
				for (int n=0; n<kernel_size; n++) {
					convolve_sum += kernel_2[m][n] * arr[i+m][j+n];
				}
			}
			convolve_average = convolve_sum / (kernel_size * kernel_size);
			resultant_2[i][j] = convolve_average;
		}
		convolve_sum = 0;
	}
	for (int j=0; j<=(arr_size - kernel_size); j++) {
		for (int i=0; i<=(arr_size - kernel_size); i++) {
			for (int m=0; m<kernel_size; m++) {
				for (int n=0; n<kernel_size; n++) {
					convolve_sum += kernel_3[m][n] * arr[i+m][j+n];
				}
			}
			convolve_average = convolve_sum / (kernel_size * kernel_size);
			resultant_3[i][j] = convolve_average;
		}
		convolve_sum = 0;
	}
}

void display(float** resultant_1, float** resultant_2, float** resultant_3) {
	for (int i=0; i<7; i++) {
		for (int j=0; j<7; j++) {
			printf("%f, ",resultant_1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i=0; i<7; i++) {
		for (int j=0; j<7; j++) {
			printf("%f, ",resultant_2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i=0; i<7; i++) {
		for (int j=0; j<7; j++) {
			printf("%f, ",resultant_3[i][j]);
		}
		printf("\n");
	}
}
