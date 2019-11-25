NAME = fillit

HEDR = fillit.h

LIBFT = libft/

SRCS = Fillit/check_input.c Fillit/main.c

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C $(LIBFT) fclean && make -C $(LIBFT)
	gcc -o $(NAME) -Wall -Werror -Wextra $(OBJECTS) libft.a

.PHONY: clean fclean re

clean:
	rm -f $(OBJECTS)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
