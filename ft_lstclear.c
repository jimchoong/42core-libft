#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (*lst)
	{
		tmp = (*lst)->next;
		while (*lst)
		{
			ft_lstdelone(*lst, del);
			*lst = tmp;
			if (*lst)
				tmp = (*lst)->next;
		}
	}
	*lst = NULL;
}
