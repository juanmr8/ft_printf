# **************************************************************************** #
#                                   Makefile                                   #
# **************************************************************************** #

# Program Name
NAME = libftprintf.a

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source Files
SRCS = ft_printf.c \
	ft_printf_utils.c

# Object Files
OBJS = $(SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re