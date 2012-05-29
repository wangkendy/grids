#include <stdio.h>
#include <stdlib.h>

int mypow(int a, int n)
{
	int r;
	if(n == 1)
		return a;
	if(n % 2 == 0) {
		r = mypow(a, n/2);
		return r * r;
	} else {
		r = mypow(a, n/2);
		return r * r * a;
	}
}

int main()
{
	int a, n;
	scanf("%d %d", &a, &n);
	printf("%d^%d=%d\n", a, n, mypow(a, n));
	return 0;
}
