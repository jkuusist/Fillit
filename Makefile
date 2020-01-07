# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/07 15:49:57 by jkuusist          #+#    #+#              #
#    Updated: 2020/01/07 16:49:51 by jkuusist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit 

HEDR = fillit.h

LIBFT = ./Libft

SRCS = main.c solver.c binary_checker.c map_shifters.c check_input.c \
	   handle_tblocks.c mask_create.c create_block_array.c print_map.c \
	   square_root.c map_stampers.c

OBJECTS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra
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
