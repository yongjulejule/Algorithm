
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_SIZE 3000

//data를 모두 분리해서 arr에 넣음
void	merge(int *arr, int left, int mid, int right)
{
	int i, j, k;
	int n1;
	int n2;
	int *L;
	int *R;

	n1 = mid - left + 1;
	n2 = right - mid;
	L = (int*)malloc(sizeof(int) * n1);
	R = (int*)malloc(sizeof(int) * n2);
	i = 0;
	while (i < n1)
	{
		L[i] = arr[left + i];
		i++;
	}
	j = 0;
	while (j < n2)
	{
		R[j] = arr[mid + 1 + j];
		j++;
	}
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else 
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	free(R);
	free(L);
}

//데이터를 1개씩 남을 때 까지 재귀로 분리 -> 합치는 과정에서 정렬하며 합쳐줌!!
void	merge_sort(int *arr, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = left + (right - left) / 2; // 그냥 left + right 연산시의 overflow를 방지할 수 있음...!
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
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
	merge_sort(arr, 0, ARR_SIZE - 1);
	end = clock();
	res = (double)(end - start);
	printf("after sort\n");
	for (int i = 0; i<ARR_SIZE; i++)
		printf("%dth element is %d\n", i, arr[i]);	
	free(arr);
	printf("time taken:%fms\n",res);
}
