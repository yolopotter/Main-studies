NAME		= pipex
CC			= cc
CFLAGS		= -Wextra -Wall -Werror

LIBFT_DIR 	= ./libft
LIBFT 		= $(LIBFT_DIR)/libft.a

OBJ_DIR		= obj/
SRC_DIR		= src/

HEADERS		= -I ./inc -I $(LIBFT_DIR)/inc

LIBFTH		= ./libft/inc/libft.h
PIPEXH		= ./inc/pipex.h

SRC			=	pipex.c \
				utils.c \
				error.c \
				fail.c \
				init.c \
				cleanup.c

OBJS		= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(PIPEXH) $(LIBFTH)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(LIBFT) $(OBJS) $(PIPEXH) $(LIBFTH)
	@$(CC) $(OBJS) $(LIBFT) $(HEADERS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all, clean, fclean, re
