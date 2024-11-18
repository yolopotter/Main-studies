#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

void	test_max_int()
{
	int fd = open("test_max_int.txt", O_CREAT | O_WRONLY, 0644);
	if (fd != -1)
	{
		ft_putnbr_fd(2147483647, fd);
		close(fd);
	}
	else
		perror("Error opening/creating file");
}

void	test_min_int()
{
	int fd = open("test_min_int.txt", O_CREAT | O_WRONLY, 0644);
	if (fd != -1)
	{
		ft_putnbr_fd(-2147483648, fd);
		close(fd);
	}
	else
		perror("Error opening/creating file");
}

void	test_int()
{
	int fd = open("test_int.txt", O_CREAT | O_WRONLY, 0644);
	if (fd != -1)
	{
		ft_putnbr_fd(546547, fd);
		close(fd);
	}
	else
		perror("Error opening/creating file");
}

void	test_zero()
{
	int fd = open("test_zero.txt", O_CREAT | O_WRONLY, 0644);
	if (fd != -1)
	{
		ft_putnbr_fd(0, fd);
		close(fd);
	}
	else
		perror("Error opening/creating file");
}

int main()
{
	test_max_int();
	test_min_int();
	test_int();
	test_zero();
	return 0;
}
