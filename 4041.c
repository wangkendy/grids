#include <stdio.h>
#include <stdlib.h>

int get_bits(int num) 
{
	int bits = 0;
	while(num != 0) {
		bits++;
		num /= 10;
	}
	return bits;
}

int main()
{
	int x1, y1, x2, y2;
	int **A, **B, **C;
	int i, j, k;
	scanf("%d %d", &x1, &y1);
	A = (int **) malloc(sizeof(int *) * x1);
	for(i = 0; i < x1; i++) {
		A[i] = (int *) malloc(sizeof(int) * y1);
		for(j = 0; j < y1; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	scanf("%d %d", &x2, &y2);
	B = (int **) malloc(sizeof(int *) * x2);
	for(i = 0; i < x2; i++) {
		B[i] = (int *) malloc(sizeof(int) * y2);
		for(j = 0; j < y2; j++) {
			scanf("%d", &B[i][j]);
		}
	}

	int *max;
	char **format;
        int bits = 0;
	if(y1 == x2) {
		C = (int **) malloc(sizeof(int *) * x1);
		max = (int *) malloc(sizeof(int) * x1);
		format = (char **) malloc(sizeof(char *) * x1);
		for(i = 0; i < x1; i++) {
			C[i] = (int *) malloc(sizeof(int) * y2);
			format[i] = (char *) malloc(sizeof(char) * 10);
		}
		for(i = 0; i < x1; i++) {
			max[i] = 0;
			for(j = 0; j < y2; j++) {
				C[i][j] = 0;
				for(k = 0; k < y1; k++) {
					C[i][j] += A[i][k] * B[k][j];
				}
				if(max[i] < C[i][j]) {
					max[i] = C[i][j];
				}
			}
			bits = get_bits(max[i]);
			if(i != 0) {
				sprintf(format[i], "%%%dd", bits + 2);	
			} else {
				sprintf(format[i], "%%%dd", bits);
			}
			//printf("%s\n", format[i]);
		}
		for(i = 0; i < y2; i++) {
			for(j = 0; j < x1; j++) {
				printf(format[j], C[j][i]);
			}
			printf("\n");
		}
	} else { // output A'
		max = (int *) malloc(sizeof(int) * x1);
		format = (char **) malloc(sizeof(char *) * x1);
		for(i = 0; i < x1; i++) {
			format[i] = (char *) malloc(sizeof(char) * 10);
		}
		for(i = 0; i < x1; i++) {
			max[i] = 0;
			for(j = 0; j < y1; j++) {
				if(max[i] < A[i][j])
					max[i] = A[i][j];
			}
			bits = get_bits(max[i]);
			if(i != 0) {
				sprintf(format[i], "%%%dd", bits + 2);
			} else {
				sprintf(format[i], "%%%dd", bits);
			}
		}
		for(i = 0; i < y1; i++) {
			for(j = 0; j < x1; j++) {
				printf(format[j], A[j][i]);
			}
			printf("\n");
		}
	}
	return 0;
}
