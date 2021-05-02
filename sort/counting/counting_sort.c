#include<stdio.h>
#include<stdlib.h>
#define SIZE 42
#define MAX_VALUE 21 

//origin = A, sorted = B, tmp = C
int		*countingSort(int *origin, int *sorted)
{
	int tmp[MAX_VALUE];
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < MAX_VALUE)
	{
		tmp[i] = 0;
		i++;
	}
	while (j < SIZE)
	{
		tmp[origin[j]]++;
		j++;
	}
	i = 1;
	while (i < MAX_VALUE)
	{
		tmp[i] = tmp[i] + tmp[i-1];
		i++;
	}
	while (0 < j)
	{
		sorted[tmp[origin[j]]] = origin[j];
		tmp[origin[j]] = tmp[origin[j]] - 1;
		j--;
	}
	return (sorted);
}

int		main(void)
{
	int *origin;
	int *sorted;
	int i;

	i = 1;
	sorted = (int*)malloc(sizeof(int)*SIZE);
	if (sorted == NULL)
		return 1;
	origin = (int*)malloc(sizeof(int)*SIZE);
	if (origin == NULL)
		return 1;
	srand(42);
	while (i < SIZE)
	{
		origin[i] = rand()%MAX_VALUE;
		printf("%dth origin data is %d\n", i, origin[i]);
		i++;
	}
	sorted = countingSort(origin, sorted);
	i = 1;
	while (i < SIZE)
	{
		printf("%dth sorted data is %d\n", i, sorted[i]);
		i++;
	}
	free(sorted);
	free(origin);
}
