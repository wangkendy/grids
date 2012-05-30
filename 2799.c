/*
 * source: http://poj.grids.cn/practice/2799/
 * tag: string manipulation
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Number {
	char value[51];
	int dot;
};

int main()
{
	int N;
	int index = 0;
	int i, j = 0;
	char input[51];
	struct Number *numbers;
	scanf("%d", &N);
	numbers = (struct Number*) malloc(sizeof(struct Number) * N);
	while (N--) {
		scanf("%s", numbers[j].value);
		i = strstr(numbers[j].value, ".") - numbers[j].value;
		if (index < i) index = i;
		numbers[j].dot = i;
		j++;
	}

	int k;
	for (i = 0; i < j; i++) {
		N = index - numbers[i].dot;
		for (k = 0; k < N; k++)
			printf(" ");
		printf("%s\n", numbers[i].value);
	}
	free(numbers);
	return 0;
}
