RESET = \033[0m
TEAL = \033[36m
GREEN = \033[32m
PURPLE = \033[35m
RED = \033[31m

NAME = push_swap

MY_SOURCES = ft_hex.c \
			 ft_nbr.c \
			 ft_printf.c \
			 ft_putstr.c \
			 ft_hnbrlen.c \
			 ft_nbrlen.c \
			 ft_putchar.c \
			 ft_strchr.c \
			 push_swap.c \
			 ft_newnode.c \
			 ft_putnbr.c \
			 ft_writenum.c \
			 ft_atol.c \
			 ft_memcpy.c \
			 ft_split.c \
			 ft_checknumber.c \
			 ft_isdigit.c \
			 ft_getlist.c \
			 ft_error.c \
			 ft_checkspaces.c \
			 ft_lst_addback.c \
			 ft_swap.c \
			 ft_push.c \
			 ft_rotate.c \
			 ft_reverse_rotate.c \
			 ft_printstacks.c \
			 ft_normalize.c \
			 ft_memset.c \
			 ft_calloc.c \
			 ft_bzero.c \
			 ft_start_alg.c \
			 ft_end.c \
			 ft_check_order.c \

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = gcc
CFLAGS += -Wall -Werror -Wextra -fsanitize=address

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(MY_OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME) $(MY_OBJECTS)
	@printf "$(TEAL)Work in progress$(RESET)"
	@for i in $$(seq 3); do \
		printf "$(TEAL).$(RESET)"; \
		sleep 1; \
		done
	@printf "\n$(GREEN)Everything's done.\n$(RESET)"

all: $(NAME)

clean:
	@rm -f $(MY_OBJECTS)
	@printf "$(PURPLE)Objects are deleted.\n$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@printf "$(RED)Everything's gone.\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re
