#include <stdio.h>
#include <string.h>
#include "libft.h"

void	test_simple()
{
	printf("test_simple\n");
	char arr[] = "--_abcd_--";
	char set[] = "-";
	char *dst = ft_strtrim(arr, set);
	printf("%s \n\n", dst);
	free(dst);
}

void	test_trim_start()
{
	printf("trim start\n");
	char arr[] = "--_abcd";
	char set[] = "-_";
	char *dst = ft_strtrim(arr, set);
	printf("%s \n\n", dst);
	free(dst);
}

void	test_trim_end()
{
	printf("trim end\n");
	char arr[] = "abcd--_";
	char set[] = "-_";
	char *dst = ft_strtrim(arr, set);
	printf("%s \n\n", dst);
	free(dst);
}

void	test_set_empty()
{
	printf("set empty\n");
	char arr[] = "abcd--_";
	char set[] = "";
	char *dst = ft_strtrim(arr, set);
	printf("%s \n\n", dst);
	free(dst);
}

void	test_s1_empty()
{
	printf("s1 empty\n");
	char *s1 = "";
	char *s2 = "";
	char *dst = ft_strtrim(s1, " \n\t");
	if (!strcmp(dst, s2))
		printf("Test passed\n");
	else
		printf("Test failed\n");
	free(dst);
}

void	test_trim_everything()
{
	printf("trim everything\n");
	char arr[] = "------";
	char set[] = "-";
	char *dst = ft_strtrim(arr, set);
	printf("%s \n\n", dst);
	free(dst);
}


void	test_NULL()
{
	printf("test NULL\n");
	char arr[] = "------";
	char set[] = "-";
	char *dst = ft_strtrim(NULL, set);
	printf("Null Input s1: %s\n", dst ? dst : "NULL");

	dst = ft_strtrim(arr, NULL);
	printf("Null Input s1: %s\n", dst ? dst : "NULL");
	free(dst);
}

void	test_memKO2()
{
	printf("MEM_KO2\n");
	char arr[] = "";
	char set[] = "123";
	char *dst = ft_strtrim(arr, set);
	printf("%s \n\n", dst);
	free(dst);
}

int main()
{
	test_simple();
	test_trim_start();
	test_trim_end();
	test_set_empty();
	test_s1_empty();
	test_trim_everything();
	test_NULL();
	//test_memKO();
	test_memKO2();
	return 0;
}


