NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf ft_printf_buffer
LIBFT = libft.a

RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
	
all: $(NAME)

$(NAME): $(LIBFT) $(SRC:=.o)
	@ar rcs $(NAME) $(SRC:=.o)
	
$(LIBFT):
ifeq (,$(wildcard libft/))
	@make install
else
	@$(MAKE) -C libft fclean
	@make update
endif
	@$(MAKE) -C libft bonus
	@cp libft/libft.a .
	@cp libft/libft.h .
	@mv libft.a $(NAME)
	@echo "$(GREEN)libftprintf.a created"

.PHONY: clean fclean re all install uninstall update

install:
ifeq (,$(wildcard libft/))
	@git clone https://github.com/bascb/42_libft.git libft
	@echo "$(GREEN)libft cloned to libft folder"
else
	@echo "$(YELLOW) libft folder already exists"
	@make update
endif

uninstall:
	@rm -rf libft
	@echo "$(YELLOW) libft folder removed"

update:
ifneq (,$(wildcard libft/))
	@echo "$(YELLOW) updating libft library"
	@git -C libft pull origin master
	@echo "$(GREEN)libft library updated"
else
	@echo "$(YELLOW) libft folder do not exists"
	@make install
endif

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f libft.a
	rm -f libft.h
ifneq (,$(wildcard libft/))
	$(MAKE) -C libft fclean
endif

re: fclean all
