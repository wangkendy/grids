#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void permutation(char *str, int m, int len)
{
	if (m < len-1){
		permutation(str, m+1, len);
		char temp;
		int i;
		for(i = m+1; i < len; i++) {
			temp = str[i];
			str[i] = str[m];
			str[m] = temp;
			permutation(str, m+1, len);
			temp = str[i];
			str[i] = str[m];
			str[m] = temp;
		}
	} else
		printf("%s\n", str);
}

int main()
{
	char str[7];
	scanf("%s", str);
	permutation(str, 0, strlen(str));
	return 0;
}
