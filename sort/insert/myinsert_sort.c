
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_SIZE 3000

void	insertion_sort(int *arr)
{
	int key;
	int i;
	int j;

	i = 1;
	while (i < ARR_SIZE)
	{
		key = arr[i]; //최초 key값
		j = i - 1;
		while (j >= 0 && arr[j] > key) // 처음 까지 가거나, 정렬 안된걸 >>로 밀음
		{
			arr[j + 1] = arr[j]; // >> 이동
			j--;
		}
		arr[j+1] = key; //밀어내고 빈 자리에 key값을 넣음
		i++;
	}
}

int		main()
{
	int *arr;
	clock_t start, end;
	double res;

	arr = (int*)malloc(sizeof(int) * ARR_SIZE);
	for (int i = 0; i<ARR_SIZE; i++)
		arr[i] = rand() % 20000 + 1;
	printf("origin arr is \n");
	for (int i = 0; i<ARR_SIZE; i++)
		printf("%dth element is %d\n", i, arr[i]);	
	start = clock();
	insertion_sort(arr);
	end = clock();
	res = (double)(end - start);
	printf("after sort\n");
	for (int i = 0; i<ARR_SIZE; i++)
		printf("%dth element is %d\n", i, arr[i]);	
	free(arr);
	printf("time taken:%f", res);
}
