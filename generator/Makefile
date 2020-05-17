
NAME 				= Generator

CC 					= gcc

SOURCE 				=\
					ft_generator.c\
					ft_principal.c\
					ft_link.c\
					ft_list.c

LIBFT_DIRECTORY 	= ./libft/

LIBFT 				= $(LIBFT_DIRECTORY)libft.a

LIBRARIES 			= -lft -L $(LIBFT_DIRECTORY)

INCLUDES 			= -I ./includes

FLAGS 				= -Wall -Wextra -Werror 

SOURCES_DIRECTORY 	= srcs/

OBJECTS_DIRECTORY 	= objects/

SOURCES 			= $(addprefix $(SOURCES_DIRECTORY), $(SOURCE))

OBJS 				= $(SOURCE:%.c=%.o)

OBJECTS				= $(addprefix $(OBJECTS_DIRECTORY), $(OBJS))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) 
	@$(CC) $(FLAGS) libft/objects/* $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "$(NAME) : $(GREEN)Compilation done.$(RESET)"

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS): $(SOURCES) 
	@$(CC) $(FLAGS) $(INCLUDES) -c $^
	@mv *.o $(OBJECTS_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(RED)Clean done.$(RESET)"

fclean: clean
	@$(MAKE) -sC $(LIBFT_DIRECTORY) fclean
	@rm -rf $(NAME) 
	@echo "$(RED)Fclean done.$(RESET)"

re: fclean all

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

test: all
	./Generator 10 10 3 4 5
big: all
	./Generator 10 100 30 40 50
small: all
	./Generator 10 100 30 1 1
1: all
	./Generator 10 2 1 1 1
rand: all
	ARG=`ruby -e "
4000: all
	./Generator 10 4000 10 10 10