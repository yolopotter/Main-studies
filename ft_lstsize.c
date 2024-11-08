#include "libft.h"

int	ft_listize(t_list *lst)
{
	int	len;

	len =  0;
	while(lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
