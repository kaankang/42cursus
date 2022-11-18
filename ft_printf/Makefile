NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
CC = gcc -c
RM = rm -f
AR = ar -rcs

SRC = ft_printf.c \
	ft_print_ptr.c \
	ft_printnbr.c \
	ft_print_hex.c \
	ft_printstr.c \
	ft_putchar.c \
	ft_u.c

OBJ = $(SRC:.c=*.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

$(OBJ):
	@$(CC) $(FLAGS) $(SRC)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

