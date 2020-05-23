NAME = lem_in

SRC =	src/bfs.c\
		src/ft_ants.c\
		src/ft_direct_ants.c\
		src/ft_moving_ants_2.c\
		src/ft_moving_ants.c\
		src/ft_setup_path.c\
		src/init.c\
		src/main.c\
		src/parser.c\
		src/path_1.c\
		src/path_2.c\
		src/pipes.c\
		src/reader.c\
		src/rooms_1.c\
		src/rooms_2.c\
		src/rooms_3.c\
		src/tools_1.c\
		src/tools_2.c\
		src/tools_parser_1.c\
		src/tools_parser_2.c\
		src/tools_parser_3.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

FSANITIZE = -fsanitize=address -g3

GCC = gcc

all: $(NAME)

%.o:%.c
	${CC} ${FLAGS} -c $< -o $@

$(NAME): $(OBJ)
	${CC} ${FLAGS} ${OBJ} -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: re, clean, fclean, all, bonus