NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf
LIBFT = libft/libft.a
	
all: $(NAME)

$(NAME): $(LIBFT) $(SRC:=.o)
ifneq (,$(wildcard libft/))
	ar rcs $(NAME) $^
else
	@echo "$(LIBFT) not found!"
endif
	
$(LIBFT):
ifneq (,$(wildcard libft/))
	libft/make re
else
	make install
endif

.PHONY: clean fclean re all install

install:
	@git clone https://github.com/bascb/42_libft.git libft
	@echo "libft cloned to libft folder"

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all