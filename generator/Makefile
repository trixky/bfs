# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/23 15:29:35 by paszhang          #+#    #+#              #
#    Updated: 2020/05/23 15:29:36 by paszhang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = generator

SRCS =	srcs/ft_generator.c\
		srcs/ft_principal.c\
		srcs/ft_link.c\
		srcs/ft_list.c\
		srcs/ft_atoi.c\
		srcs/ft_is_int.c\
		srcs/ft_putstr.c\
		srcs/ft_putstrnb.c\
		srcs/ft_randnumb.c\
		srcs/ft_base_10.c\
		srcs/ft_putnbr.c\
		srcs/ft_putstrendl.c

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
	rm -rf $(OBJ)

fclean: clean
	rm -rf ${NAME} 
	
re: fclean all

.PHONY: re, clean, fclean, all, bonus
