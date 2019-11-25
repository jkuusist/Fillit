NAME = libft.a

HEDR = libft.h

LIBFT = ../../libft

SRCS = ft_*.c

INCLUDES = $(LIBFT)/includes

OBJECTS = $(SRCS:.c=.o)

PROGRAM = ../../get_next_line.c

PROGRAM_OBJ = $(PROGRAM:.c=.o)

all: $(NAME)

$(NAME):
	make -C $(LIBFT) fclean && make -C $(LIBFT)

.PHONY: clean fclean re testing

clean:
	rm -f *.o
	rm -f ../../*.o
	rm -f $(LIBFT)/$(OBJECTS)

fclean: clean
	rm -f $(NAME)
	rm test_gnl
	make -C $(LIBFT) fclean

re: fclean all

testing:
	clang -Wall -Wextra -Werror -I $(INCLUDES) -o $(PROGRAM_OBJ) -c $(PROGRAM)
	clang -Wall -Wextra -Werror -I $(INCLUDES) -o main.o -c main.c
	clang -o test_gnl main.o $(PROGRAM_OBJ) -I $(INCLUDES) -L $(LIBFT) -lft	
