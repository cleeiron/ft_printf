# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cleiron <cleiron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/23 17:01:32 by cleiron           #+#    #+#              #
#    Updated: 2026/10/26 10:42:38 by cleiron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rcs

SRCS = ft_printf.c \
       ft_conversion.c \
       ft_print_char.c \
       ft_print_str.c \
       ft_print_nb.c \
       ft_print_nb_base.c \
       ft_print_adress.c \
       ft_strlen.c

OBJS = $(SRCS:.c=.o)

TEST = test

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME) main.c
	$(CC) $(CFLAGS) main.c $(NAME) -o $(TEST)
	./$(TEST)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

.PHONY: all clean fclean re test