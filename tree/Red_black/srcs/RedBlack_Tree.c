#include "rbt.h"

t_rbt	*initNode(t_rbt *newnode, t_rbt *nil, int key)
{
	newnode->parent = nil;
	newnode->left = nil;
	newnode->right = nil;
	newnode->key = key;
	return (newnode);
}

t_rbt	*makeNil(t_rbt *nil)
{
	nil->parent = NULL;
	nil->left = NULL;
	nil->right = NULL;
	nil->key = 0;
	nil->color = BLACK;
	return (nil);
}
void	inOrdertoPrint(t_rbt *tree, t_rbt *nil)
{
	if (tree != nil)
	{
		inOrdertoPrint(tree->left, nil);
		printf("key : %d, color : %d\n", tree->key, tree->color);
		inOrdertoPrint(tree->right, nil);
	}
}
int 	main(void)
{
	t_rbt **root;
	t_rbt *nil;
	int i;
	int j = 0;
	nil = (t_rbt*)malloc(sizeof(t_rbt));
	nil = makeNil(nil);
	root = (t_rbt**)malloc(sizeof(t_rbt*));
	*root = nil;
	srand(42);
	while (j < 10)
	{
		i = rand() % 242 + 1;
		printf("%d, ", i);
		RBinsert(root, nil, i);
		printf("key : %d, color : %d\n", (*root)->key, (*root)->color);
		j++;
	}
	inOrdertoPrint(*root, nil);
}
