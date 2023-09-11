#include "../so_long.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*thenewnode;

	thenewnode = malloc(sizeof(t_stack));
	if (!thenewnode)
		return (NULL);
	thenewnode->content = content;
	thenewnode->next = NULL;
	return (thenewnode);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_free_stack(t_stack **a)
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}
