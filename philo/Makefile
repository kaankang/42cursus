NAME = philo
CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS =  main.c \
		control.c \
		creat.c \
		control_dead.c \
		rutin.c \
		utils.c \

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
