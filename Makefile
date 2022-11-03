NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf
	
all: $(NAME)

$(NAME): $(SRC:=.o)
	ar rcs $(NAME) $^

.PHONY: clean fclean re all

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all