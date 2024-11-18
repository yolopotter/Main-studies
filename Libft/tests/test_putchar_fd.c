#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int main() {
	// Test with standard output (fd = 1)
	ft_putchar_fd('A', 1);

	// Test with standard error (fd = 2)
	ft_putchar_fd('B', 2);

	// Test with a file
	int fd = open("test_output.txt", O_CREAT | O_WRONLY, 0644);
	if (fd != -1) {
		ft_putchar_fd('C', fd);
		close(fd);
	}

	return 0;
}
