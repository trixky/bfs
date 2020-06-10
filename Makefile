# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabois <mabois@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/23 15:27:56 by mabois            #+#    #+#              #
#    Updated: 2020/05/23 15:27:59 by mabois           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bfs

SRCS =	srcs/bfs.c\
		srcs/ft_ants.c\
		srcs/ft_direct_ants.c\
		srcs/ft_moving_ants_2.c\
		srcs/ft_moving_ants.c\
		srcs/ft_setup_path.c\
		srcs/init.c\
		srcs/main.c\
		srcs/parser.c\
		srcs/path_1.c\
		srcs/path_2.c\
		srcs/pipes.c\
		srcs/reader.c\
		srcs/rooms_1.c\
		srcs/rooms_2.c\
		srcs/rooms_3.c\
		srcs/tools_1.c\
		srcs/tools_2.c\
		srcs/tools_parser_1.c\
		srcs/tools_parser_2.c\
		srcs/tools_parser_3.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

FSANITIZE = -fsanitize=address -g3

GCC = gcc

all: $(NAME)

%.o:%.c
	${CC} ${FLAGS} -c $< -o $@

$(NAME): $(OBJ)
	${CC} ${FLAGS} ${OBJ} -o $@

clean:
	make clean -C generator
	rm -rf $(OBJ)

fclean: clean
	rm -rf ${NAME}
	make fclean -C generator

extra: all
	make -C generator
	
re: fclean all

.PHONY: re, clean, fclean, all, extra
