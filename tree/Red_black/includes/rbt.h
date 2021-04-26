#ifndef RBT_H
# define RBT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum	e_Color{
	RED, 
	BLACK
}				t_Color;

typedef struct	s_rbt{
	int				key;
	t_Color			color;
	struct s_rbt	*parent;
	struct s_rbt	*left;
	struct s_rbt	*right;
}				t_rbt;

void	RBinsert(t_rbt **root,t_rbt *nil, int key);
void	rightRotate(t_rbt **root, t_rbt *nil);
void	leftRotate(t_rbt **root, t_rbt *nil);

#endif
