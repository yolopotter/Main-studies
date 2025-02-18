NAME		= philo
CC			= cc
CFLAGS		= -Wextra -Wall -Werror

OBJ_DIR		= obj/
SRC_DIR		= src/

HEADERS		= -I ./inc

SRC			=	main.c \
				exit.c

OBJS		= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(HEADERS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
