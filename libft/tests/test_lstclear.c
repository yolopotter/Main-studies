#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void	del_function(void *content)
{
	free(content);
}

void	print_list(t_list *head)
{
	t_list *current = head;
	while (current != NULL)
	{
		printf("%s -> ", (char *)current->content);
		current = current->next;
	}
	printf("NULL\n");
}

void	test_full_clear()
{
	t_list	*head = NULL;

	char *arr1 = strdup("abc");
	char *arr2 = strdup("lorem");
	char *arr3 = strdup("dolor");
	char *arr4 = strdup("sit");

	t_list	*node1 = ft_lstnew(arr1);
	t_list	*node2 = ft_lstnew(arr2);
	t_list	*node3 = ft_lstnew(arr3);
	t_list	*node4 = ft_lstnew(arr4);

	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node3);
	print_list(head);
	printf("Last node content: %s\n", (char *)ft_lstlast(head)->content);

	ft_lstadd_front(&head, node4);
	print_list(head);
	printf("Last node content: %s\n", (char *)ft_lstlast(head)->content);

	ft_lstclear(&head, del_function);
	if (head == NULL)
		printf("List successfully cleared.\n");
	else
		printf("List not fully cleared.\n");
}

void	test_partial_clear()
{
	t_list	*head = NULL;

	char *arr1 = strdup("abc");
	char *arr2 = strdup("lorem");
	char *arr3 = strdup("dolor");
	char *arr4 = strdup("sit");

	t_list	*node1 = ft_lstnew(arr1);
	t_list	*node2 = ft_lstnew(arr2);
	t_list	*node3 = ft_lstnew(arr3);
	t_list	*node4 = ft_lstnew(arr4);

	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node3);
	ft_lstadd_front(&head, node4);

	printf("Original list:\n");
	print_list(head);

	node3->next = NULL;
	ft_lstclear(&node2, del_function);

	printf("After partially clearing from node2 onwards:\n");
	print_list(head);

	ft_lstclear(&head, del_function);
}

int main()
{
	test_full_clear();
	test_partial_clear();
	return 0;
}

