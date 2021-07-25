#include "push_swap.h"

t_list	*ft_lstnew(t_list *previous, void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list) * 1);
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	list->previous = previous;
	return (list);
}

t_list	*ft_lstfirst(t_list *lst)
{
	if (lst)
	{
		while (lst)
		{
			if (!(lst->previous))
				return (lst);
			lst = lst->previous;
		}
	}
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst)
		{
			if (!(lst->next))
				return (lst);
			lst = lst->next;
		}
	}
	return (lst);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*tmp;

	if (lst != NULL && *del != NULL)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			del((*lst));
			free (*lst);
			*lst = tmp;
		}
	}
	lst = NULL;
}