NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -L./mlx -lmlx -framework AppKit -framework OpenGL
SRCS =  ./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c \
		so_long.c	\
		createmap.c \
		control_move.c \
		ft_split.c \
		ft_window.c \
		move.c \
		ft_itoa.c \

OBJS= $(SRCS:.c=.o)
MINI = ./mlx/libmlx.a

all: ${NAME}


$(MINI):
	@make -C ./mlx

$(NAME): $(OBJS) $(MINI)
	@$(CC) ${CFLAGS} $(OBJS) -o $(NAME)

%.o: %.c
	@${CC} -c $^ -o $@ -Wall -Werror -Wextra

clean:
	@rm -rf ${OBJS}
	@make clean -C mlx/

fclean: clean
	@rm -rf ${NAME}
	@make clean -C mlx/

re: fclean all
