#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m, n;
	char **subjects;
	int **grades;
	int sub_avg;
	int sub_count;
	int avg;
	int count;
	int i, j, k;	

	scanf("%d %d", &m, &n);
	subjects = (char **)malloc(sizeof(char *) * n);
	for(i = 0; i < n; i++) {
		subjects[i] = (char *)malloc(sizeof(16));
		scanf("%s", subjects[i]);
	}

	grades = (int **) malloc(sizeof(int *) * m);
	for(i = 0; i < m; i++) {
		grades[i] = (int *) malloc(sizeof(int) * n);
		for(j = 0; j < n; j++) {
			scanf("%d", &grades[i][j]);
		}
	}

	for(i = 0; i < n; i++) {
		sub_count = 0;
		sub_avg = 0;
		avg = 0;
		count = 0;
		for(j = 0; j < m; j++) {
			if(grades[j][i] != 0) {
				sub_count++;
				sub_avg += grades[j][i];
				for(k = 0; k < n; k++) {
					if(grades[j][k] != 0) {
						count++;
						avg += grades[j][k];
					}
				}
			}
		}
		sub_avg /= sub_count;
		avg /= count;
	 	printf("%s %d\n", subjects[i], (avg - sub_avg));
	}

	return 0;
}
