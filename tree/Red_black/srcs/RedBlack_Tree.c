#include "rbt.h"

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

void	postOrdertoFree(t_rbt *tree,t_rbt *nil)
{
	if (tree != nil)
	{
		postOrdertoFree(tree->left, nil);
		postOrdertoFree(tree->right, nil);
		free(tree);
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

	//	int a[20]={26,17,41,14,21,30,47,10,16,19,23,28,38,7,12,15,20,35,39,3}; 게시글의 첫번째 트리와 같은 구조
	while (j < 100)
	{
		i = rand() % 20000 + 1;

		//		RBinsert(root, nil, a[j]);
		RBinsert(root, nil, i);
		j++;
	}
	RBinsert(root, nil, 4242);
	while ((*root)->parent != nil)
		*root = (*root)->parent;
	inOrdertoPrint(*root, nil);
	postOrdertoFree(*root, nil);
	free(root);
	free(nil);
}
