NAME = fillit 
#REMEMBER TO CHANGE IT SO THE EXECUTABLE IS CREATED IN THE ROOT OF THE PROJECT

HEDR = fillit.h

LIBFT = ../Libft

SRCS = main.c solver.c binary_checker.c map_shifters.c check_input.c handle_tblocks.c mask_create.c create_block_array.c print_map.c square_root.c map_stampers.c

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
