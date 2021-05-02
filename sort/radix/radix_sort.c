#include<stdio.h>
#include<stdlib.h>

#define SIZE 42 // n 과 같음!
#define MAX_VALUE 10 // MAX_VALUE 진법이 될거임
#define DIGIT 4

//origin = A, sorted = B, tmp = C
int		*countingSortwithDigit(int *origin, int *sorted, int d)
{
	int tmp[MAX_VALUE];
	int i;
	int j;
	int digit;

	i = 1;
	digit = 1;
	while (i < d)
	{
		digit *= MAX_VALUE; //마지막 자리면 1, 그 앞자리면 10 ... 이런식
		i++;
	}
	i = 0;
	j = 1;
	while (i < MAX_VALUE)
	{
		tmp[i] = 0;
		i++;
	}
	while (j < SIZE)
	{
		tmp[((origin[j] / digit) % (MAX_VALUE))]++; //값을 digit로 나눈 몫에 digit*10 으로 나눈 나머지가 그 자리에 있는 수가 됨.
		j++;
	}
	i = 1;
	while (i < MAX_VALUE)
	{
		tmp[i] = tmp[i] + tmp[i-1];
		printf("%dth value of tmp: %d\n", i-1, tmp[i-1]);
		i++;
	}
	while (0 < j)
	{
		i = (origin[j] / digit) % (MAX_VALUE); //각 자릿수를 i에 저장함
		printf("digit is %d\n", i);
		sorted[tmp[i]] = origin[j];
		tmp[i] = tmp[i] - 1;
		j--;
	}
	return (sorted);
}

int		*radixSort(int *origin, int *sorted)
{
	int i;

	i = 1;
	while (i <= DIGIT)
	{
		printf("%dth digit Error\n",i);
		sorted = countingSortwithDigit(origin, sorted, i);
		i++;
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
		origin[i] = rand() % 9000 + 1000;
		printf("%dth origin data is %d\n", i, origin[i]);
		i++;
	}
	sorted = radixSort(origin, sorted);
	i = 1;
	while (i < SIZE)
	{
		printf("%dth sorted data is %d\n", i, sorted[i]);
		i++;
	}
	free(sorted);
	free(origin);
}
