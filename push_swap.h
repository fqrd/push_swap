#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct t_list
{
	int i;
	s_list *next;
	s_list *previous;
} 				s_list;

#endif