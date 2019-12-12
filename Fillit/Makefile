NAME = fillit

HEDR = fillit.h

LIBFT = ../Libft

SRCS = create_block_array.c	main.c print_map.c binary_checker.c	create_tblocks.c map_movers.c solver.c check_input.c mask_create.c

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
