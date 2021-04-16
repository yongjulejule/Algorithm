#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX(x,y) (((x)<(y)) ? (y):(x))

typedef	struct	s_bst{
	int key;
	int height;
	struct s_bst *parent;
	struct s_bst *left;
	struct s_bst *right;
}				t_bst;

void	init_node(t_bst *newnode, int key)
{
	newnode->parent = NULL;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->key = key;
	newnode->height = 0;
}

void	inorder_to_print(t_bst *bst)
{
	if (bst != NULL)
	{
		inorder_to_print(bst->left);
		printf("%d, ", bst->height);
		inorder_to_print(bst->right);
	}
}

void	add_height(t_bst **avl)
{
	if ((avl != NULL))
		if  (*avl != NULL)
	{
	add_height(&((*avl)->left));
	add_height(&((*avl)->right));
	if (((*avl)->left != NULL) && ((*avl)->right != NULL)) //NIL을 -1로 둬야하지만, 그러면 NIL구조체를 만들어야함
		(*avl)->height = MAX((*avl)->left->height, (*avl)->right->height) + 1;
	else if ((*avl)->left == NULL)
		(*avl)->height = (*avl)->right->height + 1;
	else
		(*avl)->height = (*avl)->left->height + 1;
	}
}
void	insert_node(t_bst **root, int key)
{
	t_bst *y;
	t_bst *x;
	t_bst *newnode;

	newnode = (t_bst*)malloc(sizeof(t_bst));
	init_node(newnode, key);
	y = NULL;
	x = *root;
	while (x)
	{
		y = x;
		if (key < x->key)
			x = x->left;
		else x = x->right;
	}
	newnode->parent = y;
	if (y == NULL)
		*root = newnode;
	else if (newnode->key < y->key)
		y->left = newnode;
	else y->right = newnode;
}

void	postorder_to_free(t_bst *bst)
{
	if (bst != NULL)	
	{	
		postorder_to_free(bst->left);
		postorder_to_free(bst->right);
		free(bst);
	}
}

int main()
{
	t_bst **root;
	int i;
	int j = 0;

	root = (t_bst**)malloc(sizeof(t_bst*));
	*root = NULL;
	srand(42);
	while (j < 50) // 1 ~ 100 까지 수 중에서 50개를 트리에 삽입
	{
		i = rand() % 100 + 1;
		insert_node(root, i);
		j++;
	}
	add_height(root);
	inorder_to_print(*root); //print 하기 위한 중위 순회
	postorder_to_free(*root); //free 하기 위한 후위 순회
	free(root);
	printf("\n");
}
