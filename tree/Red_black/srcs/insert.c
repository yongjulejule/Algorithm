#include "rbt.h"

void	initNode(t_rbt *newnode, t_rbt *nil, int key)
{
	newnode->parent = nil;
	newnode->left = nil;
	newnode->right = nil;
	newnode->key = key;
}

void	RBinsertFixup(t_rbt **newnode, t_rbt *nil)
{
	t_rbt *y;
	t_rbt *z;

	z = *newnode;
	while (z->parent->color == RED)
	{
		if (z->parent == z->parent->parent->left) //부모 노드가 left인경우
		{	
			y = z->parent->parent->right; //y 는 uncle
			if (y->color == RED) //Case 1.
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else //case 2, 3
			{
				if (z == z->parent->right) //case 2
				{
					z = z->parent;
					leftRotate(&z, nil);
				}
				z->parent->color = BLACK; // case 3
				z->parent->parent->color = RED;
				rightRotate(&z->parent->parent, nil);
			}
		}
		else //부모 노드가 right인 경우. symmetric한 구조라서 좌우만 바꾸면 됨
		{
			y = z->parent->parent->left;
			if (y->color == RED)
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->left)
				{
					z = z->parent;
					rightRotate(&z, nil);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				leftRotate(&z->parent->parent, nil);
			}
		}
	}
	if (z->parent == nil) //이때는 root 노드가 된다.
		z->color = BLACK;
}

t_rbt	**RBinsert(t_rbt **root,t_rbt *nil, int key)
{
	t_rbt *y;
	t_rbt *x;
	t_rbt *newnode;

	newnode = (t_rbt*)malloc(sizeof(t_rbt));
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
	else if (key < y->key)
		y->left = newnode;
	else y->right = newnode;
	newnode->color = RED;
	RBinsertFixup(&newnode, nil);
	if((*root)->parent != nil)
		(*root) = (*root)->parent;;
	return (root);
}
