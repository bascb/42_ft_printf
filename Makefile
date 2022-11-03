NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf
LIBFT = libft/libft.a
	
all: $(NAME)

$(NAME): $(LIBFT) $(SRC:=.o)
	ar rcs $(NAME) $^
	
$(LIBFT):
ifeq (,$(wildcard libft/))
	make install
else
	$(MAKE) -C libft fclean
	make update
endif
	$(MAKE) -C libft bonus

.PHONY: clean fclean re all install uninstall update

install:
	@git clone https://github.com/bascb/42_libft.git libft
	@echo "libft cloned to libft folder"

uninstall:
	rm -rf libft

update:
	git -C libft pull origin master

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	
re: fclean all
