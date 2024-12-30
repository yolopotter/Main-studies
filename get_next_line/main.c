#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main()
{
    int     fd;
    char    *line;

    fd = open("10-2.fdf", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %s", line);
        free(line);
    }

    close(fd);
    return 0;
}

