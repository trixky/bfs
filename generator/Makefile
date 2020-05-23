
NAME 				= ft_generator

CC 					= gcc

SOURCE 				=\
					ft_generator.c\
					ft_principal.c\
					ft_link.c\
					ft_list.c

UTIL				=\
					ft_atoi.c\
					ft_is_int.c\
					ft_putstr.c\
					ft_putstrnb.c\
					ft_randnumb.c\
					ft_base_10.c\
					ft_putnbr.c\
					ft_putstrendl.c

INCLUDES 			= -I ./includes

FLAGS 				= -Wall -Wextra -Werror 

SOURCES_DIRECTORY 	= srcs/

UTIL_DIRECTORY		= utils/

OBJECTS_DIRECTORY 	= objects/

SOURCES 			= $(addprefix $(SOURCES_DIRECTORY), $(SOURCE))

UTILS 			= $(addprefix $(UTIL_DIRECTORY), $(UTIL))

OBJS 				= $(SOURCE:%.c=%.o) $(UTIL:%.c=%.o)

OBJECTS				= $(addprefix $(OBJECTS_DIRECTORY), $(OBJS))

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS) 
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "$(NAME) : $(GREEN)Compilation done.$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS): $(SOURCES) $(UTILS)
	@$(CC) $(FLAGS) $(INCLUDES) -c $^
	@mv *.o $(OBJECTS_DIRECTORY)

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(RED)Clean done.$(RESET)"

fclean: clean
	@rm -rf $(NAME) 
	@echo "$(RED)Fclean done.$(RESET)"

re: fclean all

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

test: all
	./Generator $$(ruby -e "a= (1..50).to_a.shuffle; puts a[1..5].join(' ')")
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
