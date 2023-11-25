RESET = \033[0m
TEAL = \033[46m
GREEN = \033[42m
PURPLE = \033[45m
RED = \033[41m

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
			 ft_newlist.c \
			 ft_putnbr.c \
			 ft_writenum.c \

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = gcc
CFLAGS += -Wall -Werror -Wextra

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(MY_OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME) $(MY_OBJECTS)
	@echo -n "$(TEAL)Work, work$(RESET)"
	@for i in $$(seq 3); do \
		echo -n "$(TEAL).$(RESET)"; \
		sleep 1; \
		done
	@echo "\n$(GREEN)Everything's done, mate.$(RESET)"

all: $(NAME)

clean:
	@rm -f $(MY_OBJECTS)
	@echo "$(PURPLE)Objects are deleted.$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Everything's gone.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
