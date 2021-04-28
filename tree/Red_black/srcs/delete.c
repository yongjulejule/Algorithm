#include "rbt.h"

//x는 RBT의 성질이 깨진 노드(BLACK), w는x의 자매 노드
void	RBDeleteFixup(t_rbt **root, t_rbt *x, t_rbt *nil)
{
	t_rbt *w;

	while ((x->parent != nil) && (x->color == BLACK))
	{
		if (x == x->parent->left) //x가 부모노드의 left인 경우
		{
			w = x->parent->right;
			if (w->color == RED) //Case 1
			{
				w->color = BLACK;
				w->parent->color = RED;
				leftRotate(&x->parent, nil);
				w = x->parent->right;
			}
			if ((w->left->color == BLACK) && (w->right->color == BLACK)) //Case 2
			{
				w->color = RED;
				x = x->parent;
			}
			else 
			{
				if (w->right->color == BLACK) // Case 3
				{
					w->left->color = BLACK;
					w->color = RED;
					rightRotate(&w, nil);
					w = w->parent->right;
				}
				w->color = x->parent->color; // Case 4
				x->parent->color = BLACK;
				w->right->color = BLACK;
				leftRotate(&x->parent, nil);
				break ;
			}
		}
		else
		{
			w = x->parent->left;
			if (w->color == RED)
			{
				w->color = BLACK;
				w->parent->color = RED;
				rightRotate(&x->parent, nil);
				w = x->parent->left;
			}
			if ((w->right->color == BLACK) && (w->left->color == BLACK))
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				if (w->right->color == BLACK)
				{
					w->right->color = BLACK;
					w->color = RED;
					leftRotate(&w, nil);
					w = w->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				rightRotate(&x->parent, nil);
				break ;
			}
		}
	}
}

//u의 위치에 v를 넣어주는 함수
void	RBTransplant(t_rbt **root, t_rbt *nil,  t_rbt *u, t_rbt *v)
{
	if (u->parent == nil)
		*root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else 
		u->parent->right = v;
	v->parent = u->parent;
}

t_rbt	*minimum(t_rbt *tree, t_rbt *nil)
{
	while (tree->left != nil)
		tree = tree->left;
	return (tree);
}

//z : 삭제할 노드 y : z자리에 들어올 노드 x : y의 자식노드
void	RBDelete(t_rbt **root, t_rbt *z, t_rbt *nil)
{
	t_rbt *y;
	t_rbt *x;
	int y_original_color;

	y = z;
	y_original_color = y->color;
	if (z->left == nil) //z의 자식 노드가 2개 미만인 경우
	{
		x = z->right;
		RBTransplant(root, nil, z, z->right);
	}
	else if (z->right == nil)
	{
		x = z->left;
		RBTransplant(root, nil, z, z->left);
	}
	else //z의 자식 노드가 2개인 경우
	{
		y = minimum(z->right, nil);
		y_original_color = y->color;
		x = y->right;
		if (y->parent == z) //z의 successor가 바로 왼쪽 자식 노드면 이어주면ok
			x->parent = y;
		else //저 밑에 있는 y도 삭제되므로 그 자리를 고려해줌
		{ 
			RBTransplant(root, nil, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		RBTransplant(root, nil, z, y); //이제 z를 y로 바꿔주면 ok
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;	
	}
	if (y_original_color == BLACK)
		RBDeleteFixup(root, x, nil);
	free(z);
}

t_rbt	*searchRB(t_rbt **root, t_rbt *nil, int key)
{
	t_rbt *tmp;

	tmp = *root;
	while (tmp != nil)
	{
		if (key == tmp->key)
			return (tmp);
		else if (key < tmp->key)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	return (nil);
}

//삭제할 데이터의 노드를 찾고 삭제한 트리를 리턴
t_rbt	**initRBDeletion(t_rbt **root, t_rbt *nil, int key)
{
	t_rbt *z;

	z = searchRB(root, nil, key);
	if (z == nil)
	{
		printf("해당 노드가 없습니다 \n");
		return (root);
	}
	RBDelete(root, z, nil);
	return (root);
}
