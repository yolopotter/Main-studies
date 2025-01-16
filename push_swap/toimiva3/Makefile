NAME 		= push_swap
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
LIBFTDIR 	= ./libft
LIBFT 		= $(LIBFTDIR)/libft.a
INCLUDES 	= -I$(LIBFTDIR)
OBJ_DIR		= obj/

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

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re

