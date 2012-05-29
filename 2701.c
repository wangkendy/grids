#include <stdio.h>

int none7(int num)
{
	if(num % 7 == 0)
		return 0;
	while(num != 0) {
		if(num % 10 == 7)
			return 0;
		num /= 10;
	}
	return 1;
}

int main()
{
	int i, num;
	int total = 0;
	scanf("%d", &num);
	for(i = 1; i <= num; i++) {
		if(none7(i)) {
			total += i * i;
		}
	}
	printf("%d\n", total);
	return 0;
}
