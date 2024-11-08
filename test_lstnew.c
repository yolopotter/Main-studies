#include <stdio.h>

void	test_str()
{
	printf("\nTest array: abcde\n");
	char arr[] = "abcde";
	t_list *node = ft_lstnew(arr);
	printf("Content: %s\n", node->content);
	printf("node->next = %p", node->next);
	printf("\n\n");
}

void	test_int()
{
	printf("Test int array: 1, 2, 3, 5\n");
	int arr[] = {1, 2, 3, 5};

	t_list *node = ft_lstnew(arr);

	int *content = (int *)node->content;

	for (int i = 0; i < 4; i++)
		printf("node->content[%d] = [%d]\n", i, content[i]);
	printf("node->next = %p", node->next);
	printf("\n\n");
}

void	test_NULL()
{
	printf("\nTest NULL:\n");
	t_list *node = ft_lstnew(NULL);
	printf("Content: %s\n", node->content);
	printf("node->next = %p", node->next);
	printf("\n\n");
}

int main()
{
	test_str();
	test_int();
	test_NULL();
	return 0;
}
