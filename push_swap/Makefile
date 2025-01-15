# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = \
		ALGO_main.c \
		parse_multiple.c \
		parse_single.c \
		parse_normalize.c \
		parse_utils.c \
		parsing.c \
		rotation.c \
		operators.c \
		global_utils.c \
		calculation.c \
		algo_small.c \
		algo_big.c \
		calc_utils.c

# Header files
HDRS = $(wildcard *.h)

# Object files
OBJS = $(SRCS:.c=.o)

# Output executable
NAME = push_swap

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

