#include "avl.h"

void	leftRotate(t_avl **avl, t_avl *nil)
{
	t_avl *y;
	t_avl *x;
	
	x = *avl;
	y = x->right;
	x->right = y->left;
	if (y->left != nil) //nil이면 parent를 설정하지 않음
		y->left->parent = x;
	if (x->parent == nil) //x의 parent의 자식을 y로 바꾸는 과정
		y->parent = nil;
	else if (x == x->parent->left)
		x->parent->left = y;
	else 
		x->parent->right = y;
	y->parent = x->parent; // y의 parent을 x의 parent로 변경
	y->left = x; 
	x->parent = y; // 서로 연결
	x->height = MAX(x->left->height, x->right->height) + 1;
	y->height = MAX(y->left->height, y->right->height) + 1;
}

void	rightRotate(t_avl **avl, t_avl *nil)
{
	t_avl *x;
	t_avl *y;

	x = *avl;
	y = x->left;
	x->left = y->right;
	if (y->right != nil)
		y->right->parent = x;
	if (x->parent == nil)
		y->parent == nil;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->parent = x->parent;
	y->right = x;
	x->parent = y;
	x->height = MAX(x->left->height, x->right->height) + 1;
	y->height = MAX(y->left->height, y->right->height) + 1;
}

void	updateHeight(t_avl **avl, t_avl *nil)
{
	t_avl *x;

	x = *avl;
	while (x ->parent != nil)
	{
		x->parent->height = MAX(x->parent->left->height, x->parent->right->height) + 1;
		x = x->parent;
	}
}

void	buildAVL(t_avl **avl, t_avl *nil)
{
	if (*avl != nil)
	{
		buildAVL(&(*avl)->left, nil);
		buildAVL(&(*avl)->right, nil);
		if (ABS((*avl)->right->height - (*avl)->left->height) <= 1)
		{
			return ;
		}
		else if ((*avl)->right->height > (*avl)->left->height)
		{
			if ((*avl)->right->left->height > (*avl)->right->right->height)
			{
				rightRotate(&(*avl)->right, nil);
				leftRotate(avl, nil);
			}
			else
				leftRotate(avl, nil);
			updateHeight(avl, nil);
		}
		else 
		{
			if ((*avl)->left->right->height > (*avl)->left->left->height)
			{
				leftRotate(&(*avl)->left, nil);
				rightRotate(avl, nil);
			}
			else
				rightRotate(avl, nil);
			updateHeight(avl, nil);
		}
	}
}

t_avl	*makeAVL(t_avl **avl, t_avl *nil)
{
	t_avl *root;

	buildAVL(avl, nil);
	root = *avl;
	while (root->parent != nil)
		root = root->parent;
	return (root);
}
