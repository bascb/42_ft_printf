NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf
LIBFT = libft/libft.a
	
all: $(NAME)

$(NAME): $(SRC:=.o) $(LIBFT)
ifneq (,$(wildcard libft/))
	ar rcs $(NAME) $^
else
	@echo "$(LIBFT) not found!"
endif
	
$(LIBFT):
ifneq (,$(wildcard libft/))
	libft/make re
else
	@echo "Make sure libft folder exists inside this folder"
endif

.PHONY: clean fclean re all

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all