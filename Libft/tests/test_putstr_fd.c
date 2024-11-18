#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

void ft_putstr_fd(char *s, int fd);
void ft_putchar_fd(char c, int fd);

int main()
{
    int fd = open("test_output.txt", O_CREAT | O_WRONLY, 0644);
    if (fd != -1)
	{
        ft_putstr_fd("Hello, file!\n", fd);
        close(fd);
    }
	else
        perror("Error opening/creating file");
    return 0;
}
