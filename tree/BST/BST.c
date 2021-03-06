#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct	s_bst{
	int key;
	struct s_bst *parent;
	struct s_bst *left;
	struct s_bst *right;
}				t_bst;

t_bst	*search_node(t_bst *node, int key) //recursive search
{
	if (node == NULL || node->key == key)
		return (node);
	if (node->key > key)
		return search_node(node->left, key);
	else 
		return search_node(node->right, key);
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

	delete_node = search_node(*bst, key);
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

void	inorder_to_print(t_bst *bst)
{
	if (bst != NULL)
	{
		inorder_to_print(bst->left);
		printf("%d, ", bst->key);
		inorder_to_print(bst->right);
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
	inorder_to_print(*root); //print 하기 위한 중위 순회
	printf("\n42가 있는지 확인합니다.\n");
	if (search_node(*root, 42))
		printf("존재하는 데이터 입니다.\n");
	else printf("존재하지 않는 데이터 입니다.\n");
	printf("41을 삭제합니다.\n");
	delete_node(root, 41);
	inorder_to_print(*root);
	postorder_to_free(*root); //free 하기 위한 후위 순회
	free(root);
	printf("\n");
}
