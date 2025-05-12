NAME = libftprintf.a
UNAME_M := $(shell uname -m)

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCS_DIR = ./
UTILS_DIR = ./utils/
INC_DIR = ./


SRCS = $(SRCS_DIR)ft_printf.c
UTILS_SRCS = $(UTILS_DIR)ft_putnbr_base.c $(UTILS_DIR)ft_putnbr_base_unsigned.c $(UTILS_DIR)ft_strlen.c $(UTILS_DIR)ft_putstr.c $(UTILS_DIR)ft_putchar.c $(UTILS_DIR)ft_print_pointer.c

ALL_SRCS = $(SRCS) $(UTILS_SRCS)

# Object Files
OBJS = $(ALL_SRCS:.c=.o)

INCLUDES = -I$(INC_DIR) -I$(UTILS_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
