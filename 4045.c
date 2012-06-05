#include <stdio.h>
#include <stdlib.h>

int nonen(int num, int n)
{
	int temp =  num;
	if(num % n == 0) {
		return 0;
	}

	while(num != 0) {
		if(num % 10 == n) {
			return 0;
		}
		num /= 10;
	}
	return 1;
}

int main()
{
	int num, sum = 0;
	int i;
	scanf("%d", &num);
	for(i = 1; i <= num; i++) {
		if(nonen(i, 3) && nonen(i, 5)){
			sum += i * i;
		}
	}
	printf("%d\n", sum);
}

