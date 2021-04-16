#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define K 3
#define ABS(x) ((x < 0) ? (-x) : (x))

typedef	struct	s_bst{
	int key;
	struct s_bst *parent;
	struct s_bst *left;
	struct s_bst *right;
}				t_bst;

t_bst	*search_node_to_delete(t_bst *node, int key) //recursive search
{
	if (node == NULL || node->key == key)
		return (node);
	if (node->key > key)
		return search_node_to_delete(node->left, key);
	else 
		return search_node_to_delete(node->right, key);
}

t_bst	*minimum_node(t_bst *min)
{
	while (min->left != NULL)
		min = min->left;
	return (min);
}

void	modify_deleted_node(t_bst **bst, t_bst *replace_node, t_bst *newnode)
{
	if (replace_node->parent == NULL) //root노드를 삭제하면, 새로운 노드가 root노드가 된다.
		*bst = newnode;
	else if (replace_node == replace_node->parent->left) //삭제될 노드의 자식 노드가 왼쪽 자식 노드면 왼쪽에 update 
		replace_node->parent->left = newnode;
	else replace_node->parent->right = newnode; // 오른쪽 자식 노드면 오른쪽에 update
	if (newnode != NULL) // 자식 노드가 없다면 그대로 올림.
		newnode = replace_node;
}

void	delete_node(t_bst **bst, int key)
{
	t_bst *min;
	t_bst *delete_node;
	t_bst *tmp;

	delete_node = search_node_to_delete(*bst, key);
	tmp = delete_node;
	if (delete_node == NULL)
		return ;
	if (delete_node->left == NULL) //left가 NULL이면 right가 newnode로 update
		modify_deleted_node(bst, delete_node, delete_node->right); 
	else if (delete_node->right == NULL) //right가 NULL이면 left가 newnode로 update
		modify_deleted_node(bst, delete_node, delete_node->left);
	else 
	{
		min = minimum_node(delete_node->right); //지울 노드의 successor를 찾아온다.
		if (min->parent != delete_node)
		{
			modify_deleted_node(bst, min, min->right); //min이 삭제된 노드 자리로 올라온다.
			min->right = delete_node->right;
			min->right->parent = min;
		}
		modify_deleted_node(bst, delete_node, min);
		min->left = delete_node->left;
		min->left->parent = min;
	}
	free(tmp);
}

void	init_node(t_bst *newnode, int key)
{
	newnode->parent = NULL;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->key = key;
}

int		search_node(t_bst *node, int key) //iterative search, K조건을 위해 수정한 함수
{
	while (node != NULL && (ABS((key - (node->key))) >= K)) // K분 안에 착륙을 할 수 없음.
	{
		if (key < node->key)
			node = node->left;
		else 
			node = node->right;
	}
	return ((node == NULL) ? 1 : 0);
}

void	inorder_tree_walk(t_bst *bst)
{
	if (bst != NULL)
	{
		inorder_tree_walk(bst->left);
		printf("%d, ", bst->key);
		inorder_tree_walk(bst->right);
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

void	postorder_tree_walk(t_bst *bst)
{
	if (bst != NULL)	
	{	
		postorder_tree_walk(bst->left);
		postorder_tree_walk(bst->right);
		free(bst);
	}
}

int main()
{
	t_bst **root;
	int R[] = {46, 41, 49, 37, 56};
	int i;
	char buf[6] = "";

	i = 0;
	root = (t_bst**)malloc(sizeof(t_bst*));
	*root = NULL;
	while (i < 5)
	{
		insert_node(root, R[i]);
		i++;
	}
	inorder_tree_walk(*root); //print 하기 위한 중위 순회
	printf("착륙 예정 시간을 입력하시오(2자리 정수)\n");
	read(0, buf, 2);
	i = atoi(buf);
	if (!search_node(*root, i))
		printf("해당 시간엔 착륙 할 수 없습니다.\n");
	else
	{
		insert_node(root, i);
		printf("요청한 시간에 예약되었습니다.\n");
	}
	printf("취소할 시간을 입력하세요");
	inorder_tree_walk(*root);

	read(0, buf, 2);
	i = atoi(buf);
	delete_node(root, i);
	printf("취소되었습니다.");
	inorder_tree_walk(*root);
	postorder_tree_walk(*root); //free 하기 위한 후위 순회
	free(root);
}
