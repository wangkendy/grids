#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_sub(char *str, int start, int len)
{
	int i;
	for(i = 0; i < len; i++) {
		printf("%c", str[start++]);
	}
	printf("\n");
}

int get_total(int *arr)
{
	int total = 0;
	int i = 0;
	for(i = 0; i < 100; i++) {
		total += arr[i];
	}
	return total;
}

int main()
{
	char str[101];
	int m, q, len;
	int indexs[100];
	int cases;
	int count;
	int last;
	int i;

	scanf("%d", &cases);
	for(count = 0; count < cases; count++) {
		memset(str, 0, sizeof(str));
		memset(indexs, 0, sizeof(indexs));
		last = 0;
		scanf("%s %d %d", str, &m, &q);
		for(i = 0; i < m; i++) {
			last += str[i] - 'a' + 1;
		}
		if(last == q) {
			indexs[0] = 1; 
		}
		len = strlen(str);
		for(i = 1; i <= len - m; i++) {
			last -= str[i-1] - 'a' + 1;
			last += str[i+m-1] - 'a' + 1;
			if(last == q)
				indexs[i] = 1;
		}
		printf("%d\n", get_total(indexs));
		for(i = 0; i < 100; i++) {
			if(indexs[i])
				print_sub(str, i, m);
		}
	}
	return 0;
}
