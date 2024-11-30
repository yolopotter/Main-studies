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
		ft_utoa.c \
		ft_unsigned_int.c \

OBJECTS = $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))

OBJF	=	.directory_exists

all: $(NAME)

$(NAME): $(LIBFTDIR)/$(LIBFTNAME) $(OBJECTS)
		cp $(LIBFTDIR)/$(LIBFTNAME) .
		mv $(LIBFTNAME) $(NAME)
		ar -rcs $@ $(OBJECTS)

$(LIBFTDIR)/$(LIBFTNAME):
		$(MAKE) -C $(LIBFTDIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJF):
		@mkdir -p $(OBJ_DIR)

clean:
		rm -rf $(OBJ_DIR)
		$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
		rm -rf $(NAME)
		$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
