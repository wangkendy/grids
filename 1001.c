#include <stdio.h>
#include <stdlib.h>

int* mypow(int *R, int *len, int n)
{
	int *res;
	if(n == 1) {
		*len = 5;
		return R;
	}

	if(n % 2 == 0) {
		res = mypow(R, len, n/2);
		int *temp = (int *) malloc(sizeof(int) * *len * 2);
		int i, j;
		for(i = 0; i < *len; i++) {
			for(j = 0; j < *len; j++) {
				temp[i+j] += R[i] * R[j];
			}
		}
		*len *= 2;
		return temp;
	}
}

int main()
{
	int R[5] = {9, 5, 1, 2, 3};
	int n = 4;
	int i, len;
	int *r;
	r = mypow(R, &len, n);
	for(i = 0; i < len; i++) {
		printf("%d ", r[i]);
	}
}
