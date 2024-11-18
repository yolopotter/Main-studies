#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// Helper function to create a list with given values
t_list *create_list_with_values(int *values, size_t size)
{
    t_list *head = NULL;
    t_list *new_node;
    for (size_t i = 0; i < size; i++)
    {
        new_node = ft_lstnew(malloc(sizeof(int)));
        if (!new_node || !new_node->content)
        {
            ft_lstclear(&head, free);
            return NULL;
        }
        *(int *)(new_node->content) = values[i];
        ft_lstadd_back(&head, new_node);
    }
    return head;
}

// Helper function to apply on each node's content (for mapping)
void *multiply_by_two(void *content)
{
    int *result = malloc(sizeof(int));
    if (result == NULL)
        return NULL;
    *result = (*(int *)content) * 2;
    return result;
}

// Helper function to free node content
void delete_int(void *content)
{
    free(content);
}

// Helper function to print the list of integers
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d -> ", *(int *)(lst->content));
        lst = lst->next;
    }
    printf("NULL\n");
}

// Test Case 1: Normal list with values 1, 2, 3
void test_case_1()
{
    printf("Test Case 1: Normal list\n");
    int values[] = {1, 2, 3};
    t_list *lst = create_list_with_values(values, sizeof(values) / sizeof(int));

    t_list *mapped_list = ft_lstmap(lst, &multiply_by_two, &delete_int);

    printf("Original list: ");
    print_list(lst);
    printf("Mapped list: ");
    print_list(mapped_list);

    ft_lstclear(&lst, &delete_int);
    ft_lstclear(&mapped_list, &delete_int);
}

// Test Case 2: Empty list
void test_case_2()
{
    printf("\nTest Case 2: Empty list\n");
    t_list *lst = NULL;

    t_list *mapped_list = ft_lstmap(lst, &multiply_by_two, &delete_int);

    printf("Mapped list (should be NULL): %p\n", (void *)mapped_list);
}

// Test Case 3: Null function pointer (f)
void test_case_3()
{
    printf("\nTest Case 3: Null function pointer\n");
    int values[] = {5};
    t_list *lst = create_list_with_values(values, sizeof(values) / sizeof(int));

    t_list *mapped_list = ft_lstmap(lst, NULL, &delete_int);

    printf("Mapped list (should be NULL): %p\n", (void *)mapped_list);

    ft_lstclear(&lst, &delete_int);
}

int main()
{
	test_case_1();
	test_case_2();
	test_case_3();
	return 0;
}
