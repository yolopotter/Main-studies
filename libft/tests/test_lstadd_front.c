
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void	test_str()
{
	printf("\nTest array: abcde and 12345\n");

	char arr[] = "abcde";
	char arr2[] = "12345";

	t_list *node = ft_lstnew(arr);
	printf("t_list adress:					%p\n", *node);
	printf("Content of the first node:			%s\n", node->content);
	printf("Adress of the first node:			%p\n", (void *)node->content);
	printf("node->next =					%p", (void *)node->next);
	printf("\n\n");

	t_list *new_head = ft_lstnew(arr2);
	ft_lstadd_front(&node, new_head);

	printf("Content of new head node:			%s\n", node->content);
	printf("Adress of new head node:			%p\n", (void *)node->content);
	printf("New head's next (old head) adress:		%p\n", (void *)node->next);
	printf("Content of old head node via new head's next:	%s\n", node->next->content);
	printf("node->next->next = 				%p\n", (void *)node->next->next);
	printf("\n");
	printf("Address of old t_list node:			%p\n", (void *)new_head->next);
	printf("Is node->next pointing to the original first node? %s\n", (node->next == new_head->next) ? "Yes" : "No");
	printf("\n");
	printf("--------------------------------------------------------------------\n\n");
}

void	ft_print_result(t_list *elem)
{
	int		len;

	len = 0;
	while (((char *)elem->content)[len])
		len++;
	write(1, elem->content, len);
	write(1, "\n", 1);
}

t_list	*ft_lstnewone(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	if (!content)
		elem->content = NULL;
	else
		elem->content = content;
	elem->next = NULL;
	return (elem);
}

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

	elem = ft_lstnewone(str);
	elem2 = ft_lstnewone(str2);
	elem3 = ft_lstnewone(str3);
	elem4 = ft_lstnewone(str4);
	begin = NULL;
	ft_lstadd_front(&begin, elem4);
	ft_lstadd_front(&begin, elem3);
	ft_lstadd_front(&begin, elem2);
	ft_lstadd_front(&begin, elem);
	while (begin)
	{
		ft_print_result(begin);
		begin = begin->next;
	}
}

int main()
{
	test_str();
	test_warmashine();
	return 0;
}
