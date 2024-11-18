#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int main()
{
	int fd = open("test_output.txt", O_CREAT | O_WRONLY, 0644);
	if (fd != -1)
	{
		ft_putendl_fd("Hello, file!", fd);
		close(fd);
	}
	return 0;
}
