#include <stdio.h>
#include <stdlib.h>

struct Mouse {
	int weight;
	char color[11];
};

int compare(const void *val1, const void *val2)
{
	return ((struct Mouse*)val1)->weight - ((struct Mouse*)val2)->weight;
}

int main()
{
	int count;
	int i;
	struct Mouse *mouse;
	scanf("%d", &count);
	mouse = (struct Mouse *) malloc(sizeof(struct Mouse) * count);
	for(i = 0; i < count; i++) {
		scanf("%d %s", &mouse[i].weight, mouse[i].color);
	}
	
	qsort(mouse, count, sizeof(struct Mouse), compare);

	for(i = 0; i < count; i++) {
		printf("%s\n", mouse[i].color);
	}
	return 0;
}
