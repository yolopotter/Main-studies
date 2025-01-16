NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
INCLUDES = -I$(LIBFTDIR)

SRCS = \
		algo_main.c \
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
		calculation_utils.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME) clean

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re

