#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	fill_str(char *dst, const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*dst;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = strlen(s1) + strlen(s2);
	dst = (char *)malloc((1 + len) * sizeof(char));
	if (!dst)
		return (NULL);
	fill_str(dst, s1, s2);
	return (dst);
}

void	test1()
{
	char arr1[] = "";
	char arr2[] = "123\n";
	printf("%s", ft_strjoin(arr1, arr2));
}
void	test2()
{
	char arr1[] = "abc";
	char arr2[] = "123\n";
	printf("%s", ft_strjoin(arr1, arr2));
}
void	test3()
{
	char arr1[] = "abc";
	char arr2[] = "\n";
	printf("%s", ft_strjoin(arr1, arr2));
}

int main()
{
	test1();
	test2();
	test3();
	//test4();
	return 0;
}
