Libft coontains utility functions to be used in other projects.

To use this library in other projects copy libft directory in root.
Command make will create the library libft.a.

library is located in libft/libft/libft.a

Example of including LIBFT in some projects makefile:


LIBFT_DIR 	= ./libft
LIBFT 		= $(LIBFT_DIR)/libft.a

HEADERS		= -I $(LIBFT_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT)
	@$(CC) $(OBJS) $(LIBFT) $(HEADERS) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
