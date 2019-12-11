NAME = fillit

HEDR = fillit.h

LIBFT = ../Libft

SRCS = binary_checker.c str_to_bin.c create_block_array.c check_input.c main.c 

OBJECTS = $(SRCS:.c=.o)
#REMEMBER TO REMOVE -g BEFORE FINAL PUSH
FLAGS = -Wall -Werror -Wextra -g
#REMEMBER TO REMOVE -g BEFORE FINAL PUSH
all: $(NAME)

$(NAME):
	make -C $(LIBFT) fclean
	make -C $(LIBFT)
	@gcc $(FLAGS) $(SRCS) $(LIBFT)/libft.a -o $(NAME)

.PHONY: clean fclean re

clean:
	@rm -f $(OBJECTS)
	make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
