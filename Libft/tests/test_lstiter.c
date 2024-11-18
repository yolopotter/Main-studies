#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	del_function(void *content)
{
	free(content);
}

void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

t_list	*create_node(char *content)
{
	return (ft_lstnew(content));
}

t_list	*build_list(void)
{
	char *arr1 = strdup("abc");
	char *arr2 = strdup("lorem");
	char *arr3 = strdup("dolor");

	t_list	*node1 = ft_lstnew(arr1);
	t_list	*node2 = ft_lstnew(arr2);
	t_list	*node3 = ft_lstnew(arr3);
	// Link the nodes
	node1->next = node2;
	node2->next = node3;
	return node1;
}

void	test_ft_lstiter(void)
{
	// Build the list
	t_list *head = build_list();

	printf("Testing ft_lstiter:\n");
	ft_lstiter(head, print_content); // Apply print_content to each node

	ft_lstclear(&head, del_function);
}

int	main(void)
{
	test_ft_lstiter();
	return (0);
}
