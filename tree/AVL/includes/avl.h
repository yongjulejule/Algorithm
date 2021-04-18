#ifndef AVL_H
# define AVL_H

#include <stdio.h>
#include <stdlib.h>
#define	MAX(x,y) (((x) < (y)) ? (y):(x))

#define ABS(x) (((x) < 0) ? (-(x)) : (x))

typedef	struct	s_avl{
	int key;
	int height;
	struct s_avl *parent;
	struct s_avl *left;
	struct s_avl *right;
}				t_avl;

void	addHeight(t_avl **avl, t_avl *nil);
t_avl	*makeAVL(t_avl **avl, t_avl *NIL);

#endif
