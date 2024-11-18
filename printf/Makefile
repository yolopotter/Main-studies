NAME 		= libftprintf.a
LIBFTNAME 	= libft.a
INCLUDES	= -I$(LIBFTDIR) -Iinclude
CC 			= cc
CFLAGS 		= -Wall -Werror -Wextra
LIBFTDIR 	= ./libft
SRC_DIR		= src/
OBJ_DIR		= obj/

SOURCES = \
		ft_printf.c \
		ft_char.c \
		ft_hex.c \
		ft_int.c \
		ft_pointer.c \
		ft_putnbr_base.c \
		ft_putstr.c \
		ft_string.c \
		ft_uitoa.c \
		ft_unsigned_int.c \

OBJECTS = $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))

OBJF	=	.cache_exists

all: $(NAME)

makelibft:
		make -C $(LIBFTDIR)
		cp $(LIBFTDIR)/$(LIBFTNAME) .
		mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJECTS)
		ar -rcs $(NAME) $(OBJECTS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJF):
		@mkdir -p $(OBJ_DIR)

clean:
		rm -rf $(OBJ_DIR)
		cd $(LIBFTDIR) && make clean

fclean: clean
		rm -f $(NAME)
		cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re makelibft
