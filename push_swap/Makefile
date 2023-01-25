NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS = ft_split.c \
	ft_atoi.c \
	ft_setup.c \
	function.c \
	function1.c \
	function2.c \
	push_swap.c \
	radix.c \
	utils.c \
	utils2.c \
	utils3.c \
	utils4.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

.c.o:
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

