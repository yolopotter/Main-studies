#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void	test_warmashine()
{
	t_list		*begin;
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	char		*str = strdup("lorem");
	char		*str2 = strdup("ipsum");
	char		*str3 = strdup("dolor");
	char		*str4 = strdup("sit");

	elem = ft_lstnew(str);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);
	begin = NULL;
	printf("%d\n", ft_listize(begin));
	ft_lstadd_front(&begin, elem4);
	printf("%d\n", ft_listize(begin));
	ft_lstadd_front(&begin, elem3);
	printf("%d\n", ft_listize(begin));
	ft_lstadd_front(&begin, elem2);
	printf("%d\n", ft_listize(begin));
	ft_lstadd_front(&begin, elem);
	printf("%d\n", ft_listize(begin));
}

int main()
{
	test_warmashine();
	return 0;
}
