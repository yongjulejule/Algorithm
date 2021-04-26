#include "rbt.h"

void	RBinsertFixup(t_rbt **root, t_rbt *nil, t_rbt *(*newnode))
{
	t_rbt *y;

	while ((*newnode)->parent->color == RED)
	{
		if ((*newnode)->parent == (*newnode)->parent->parent->left) //부모 노드가 left인경우
		{	
			y = (*newnode)->parent->parent->right; //y 는 uncle
			if (y->color == RED) //Case 1.
			{
				(*newnode)->parent->color = BLACK;
				y->color = BLACK;
				(*newnode)->parent->parent->color = RED;
				(*newnode) = (*newnode)->parent->parent;
			}
			else //case 2, 3
			{
				if ((*newnode) == (*newnode)->parent->right) //case 2
				{
					(*newnode) = (*newnode)->parent;
					leftRotate(&(*newnode), nil);
				}
				(*newnode)->parent->color = BLACK; // case 3
				(*newnode)->parent->parent->color = RED;
				rightRotate(&(*newnode)->parent->parent, nil);
			}
		}
		else //부모 노드가 right인 경우. symmetric한 구조라서 좌우만 바꾸면 됨
		{
			y = (*newnode)->parent->parent->left;
			if (y->color == RED)
			{
				(*newnode)->parent->color = BLACK;
				y->color = BLACK;
				(*newnode)->parent->parent->color = RED;
				(*newnode) = (*newnode)->parent->parent;
			}
			else
			{
				if ((*newnode) == (*newnode)->parent->left)
				{
					(*newnode) = (*newnode)->parent;
					rightRotate(&(*newnode), nil);
				}
				(*newnode)->parent->color = BLACK;
				(*newnode)->parent->parent->color = RED;
				leftRotate(&(*newnode)->parent->parent, nil);
			}
		}
	}
	if ((*newnode)->parent == nil)
		(*newnode)->color = BLACK;
}

void	RBinsert(t_rbt **root,t_rbt *nil, int key)
{
	t_rbt *y;
	t_rbt *x;
	t_rbt *newnode;

	newnode = (t_rbt*)malloc(sizeof(t_rbt));
	newnode = initNode(newnode, nil, key);
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
	newnode->left = nil;
	newnode->right = nil;
	newnode->color = RED;
	RBinsertFixup(root, nil, &newnode);
}
