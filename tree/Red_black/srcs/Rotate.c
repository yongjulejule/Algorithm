#include "rbt.h"

void	leftRotate(t_rbt **rbt, t_rbt *nil)
{
	t_rbt *x;
	t_rbt *y;

	x = *rbt;
	y = x->right;
	x->right = y->left;
	if (y->left != nil)
		y->left->parent = x;
	if (x->parent == nil)
		y->parent = nil;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->parent = x->parent;
	y->left = x;
	x->parent = y;
}

void	rightRotate(t_rbt **rbt, t_rbt *nil)
{
	t_rbt *x;
	t_rbt *y;

	x = *rbt;
	y = x->left;
	x->left = y->right;
	if (y->right != nil)
		y->right->parent = x;
	if (x->parent == nil)
		y->parent = nil;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->parent = x->parent;
	y->right = x;
	x->parent = y;
}
