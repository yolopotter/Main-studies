GNL to be used as such in some project.

Multiple_fd handles multiple fd's and is also better protected against malloc fails compared to single_fd version. Make sure to run fd's to the end always, othewise there will be "still reachable" in valgrind.

Including in other project can be done by creating gnl directory and then copying content to there.

Example of including GNL in some projects makefile:

GNL_DIR		= ./src/gnl

HEADERS		= -I $(GNL_DIR)

SRC			=	....
				gnl/get_next_line_utils.c gnl/get_next_line.c

```
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(HEADERS) -o $(NAME)
```

