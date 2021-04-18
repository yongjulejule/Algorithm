#include "avl.h"

void	initNode(t_avl *newnode,t_avl *nil, int key)
{
	newnode->parent = nil;
	newnode->left = nil;
	newnode->right = nil;
	newnode->key = key;
	newnode->height = 0;
}

void	inOrdertoPrint(t_avl *avl, t_avl *nil)
{
	if (avl != nil)
	{
		inOrdertoPrint(avl->left, nil);
		printf("height:%d, ", avl->height);
		printf("key: %d\n", avl->key);
		inOrdertoPrint(avl->right, nil);
	}
}

void	addHeight(t_avl **avl, t_avl *nil)
{
	if (*avl != nil)
	{
	addHeight(&(*avl)->left, nil);
	addHeight(&(*avl)->right, nil);	
	(*avl)->height = MAX((*avl)->left->height, (*avl)->right->height) + 1;
	}
}

void	insertNode(t_avl **root, t_avl *nil, int key)
{
	t_avl *y;
	t_avl *x;
	t_avl *newnode;

	newnode = (t_avl*)malloc(sizeof(t_avl));
	initNode(newnode, nil, key);
	y = nil;
	x = *root;
	while (x != nil)
	{
		y = x;
		if (key < x->key)
			x = x->left;
		else x = x->right;
	}
	newnode->parent = y;
	if (y == nil)
		*root = newnode;
	else if (newnode->key < y->key)
		y->left = newnode;
	else y->right = newnode;
}

void	postOrdertoFree(t_avl *avl, t_avl *nil)
{
	if (avl != nil)	
	{	
		postOrdertoFree(avl->left, nil);
		postOrdertoFree(avl->right, nil);
		free(avl);
	}
}

t_avl	*makeNil(t_avl *nil)
{
	nil->parent = NULL;
	nil->left = NULL;
	nil->right = NULL;
	nil->key = 0;
	nil->height = -1;
	return (nil);
}

int main()
{
	t_avl **root;
	t_avl *nil;
	int i;
	int j = 0;

	nil = (t_avl*)malloc(sizeof(t_avl));
	nil = makeNil(nil); //setting nil
	root = (t_avl**)malloc(sizeof(t_avl*));
	*root = nil;
	srand(42);
	while (j < 50) // 1 ~ 100 까지 수 중에서 50개를 트리에 삽입
	{
		i = rand() % 100 + 1;
		printf("%d번째 입력 : %d, ",j, i);
		insertNode(root, nil, i);
		j++;
	}
	addHeight(root, nil);
	*root = makeAVL(root, nil);
	inOrdertoPrint(*root, nil);
	postOrdertoFree(*root, nil); //free 하기 위한 후위 순회
	free(root);
	printf("\n");
}
