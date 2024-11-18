#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void	test_lstadd_back()
{
	t_list	*begin = NULL;

	char *arr1 = strdup("first");
	char *arr2 = strdup("second");
	char *arr3 = strdup("third");

	ft_lstadd_back(&begin, ft_lstnew(arr1));
	printf("last node content: %s\n", (char *)ft_lstlast(begin)->content);

	ft_lstadd_back(&begin, ft_lstnew(arr2));
	printf("last node content: %s\n", (char *)ft_lstlast(begin)->content);

	ft_lstadd_back(&begin, ft_lstnew(arr3));
	printf("last node content: %s\n", (char *)ft_lstlast(begin)->content);
}

int main()
{
	test_lstadd_back();
	return 0;
}
