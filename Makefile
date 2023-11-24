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
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(MY_OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $(MY_OBJECTS)

all: $(NAME)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
