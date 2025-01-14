# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = \
		ALGO_main.c \
		parse_multiple.c \
		parse_single.c \
		parsing_normalize.c \
		parsing_utils.c \
		parsing.c

# Header files
HDRS = $(wildcard *.h)

# Object files
OBJS = $(SRCS:.c=.o)

# Output executable
NAME = a.out

# Rules
all: $(NAME) clean

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

