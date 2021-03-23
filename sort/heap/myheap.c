
#include <stdio.h>
#include <stdlib.h>
#define HEAPSIZE 30

typedef struct	s_heap{
	int *heap;
	int size;
}				t_heap;

void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
// subtree를 최대 힙으로 만들어줌. idx = current node
void    Max_heapify(t_heap *pheap, int idx)
{
	int left;
	int right;
	int largest;

	largest = idx;
	left = idx * 2;
	right = idx * 2 + 1;
	if (pheap->heap[largest] < pheap->heap[left] && left < pheap->size)
		largest = left;
	if (pheap->heap[largest] < pheap->heap[right] && right < pheap->size)
		largest = right;
	if (largest != idx)
	{
		swap(&pheap->heap[idx], &pheap->heap[largest]);
		Max_heapify(pheap, idx);
	}
}

// tree 를 최대 힙으로 만들어줌.
void    build_max_heap(t_heap *pheap)
{
	int idx;

	idx = pheap->size / 2;
	while (idx > 0) //heapsize / 2 ~ heapsize까지는 자식노드이므로 여기까지만 보면 OK
	{
		Max_heapify(pheap, idx);
		idx--;
	}
}

int     *expend_heap(t_heap *pheap)
{
	int *tmp;
	int idx;

	idx = -1;
	pheap->size++;
	tmp = (int*)malloc(sizeof(int) * pheap->size);
	while (++idx < pheap->size - 1)
		tmp[idx] = pheap->heap[idx];
	free(pheap->heap);
	return (tmp);
}

void    insert_heap(t_heap *pheap, int newdata)
{
	pheap->heap = expend_heap(pheap);
	pheap->heap[pheap->size - 1] = newdata;
	build_max_heap(pheap);
}

void    delete_heap(t_heap *pheap)
{
	swap(&pheap->heap[1], &pheap->heap[pheap->size - 1]);
	pheap->size--;
	build_max_heap(pheap);
}

void    heap_sort(t_heap *pheap)
{
	while(pheap->size > 1)
	{
		swap(&pheap->heap[1], &pheap->heap[pheap->size - 1]);
		pheap->size--;
		build_max_heap(pheap);
	}
}

int     main()
{
	int     *test;
	t_heap  *pheap;

	pheap = (t_heap*)malloc(sizeof(t_heap));
	test = (int*)malloc(sizeof(int) * (HEAPSIZE + 1));
	for (int i = 1; i < 31; i++)
		test[i] = rand() % 200 + 1;
	pheap->heap = test;
	printf("origin array\n");
	for (int i = 1; i < 31; i++)
		printf("%dth node in heap is %d\n", i, pheap->heap[i]);
	pheap->size = HEAPSIZE + 1;
	build_max_heap(pheap);
	printf("origin heap\n");
	for (int i = 1; i < 31; i++)
		printf("%dth node in heap is %d\n", i, pheap->heap[i]);
	insert_heap(pheap, 171);
	printf("insert 171\n");
	for (int i = 1; i < 32; i++)
		printf("%dth node in heap is %d\n", i, pheap->heap[i]);
	delete_heap(pheap);
	printf("delete a node\n");
	for (int i = 1; i < 31; i++)
		printf("%dth node in heap is %d\n", i, pheap->heap[i]);
	heap_sort(pheap);
	printf("heap sort\n");
	for (int i = 0; i < 31; i++)
		printf("%dth node in heap is %d\n", i, pheap->heap[i]);

	free(pheap->heap);
	free(pheap);
}
