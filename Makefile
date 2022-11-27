NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf ft_printf_buffer ft_printf_str ft_printf_chr ft_printf_int\
	ft_printf_uns ft_printf_hex ft_printf_pointer
LIBFT = libft.a

RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
	
all: $(NAME)

$(NAME): $(LIBFT) $(SRC:=.o)
	@ar rcs $(NAME) $(SRC:=.o)
	
$(LIBFT):
	@$(MAKE) -C libft bonus
	@cp libft/libft.a .
	@cp libft/libft.h .
	@mv libft.a $(NAME)
	@echo "$(GREEN)libftprintf.a created"

.PHONY: clean fclean re all bonus

bonus: re

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
