#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void	del_function(void *content)
{
	free(content);
}

void	test_str()
{
	char *arr = strdup("abcd");
	t_list *lst = ft_lstnew(arr);
	printf("Content: %s\n", lst->content);

	ft_lstdelone(lst, del_function);
}

int main()
{
	test_str();
	return 0;
}
