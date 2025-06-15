# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weiyang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/15 14:49:34 by weiyang           #+#    #+#              #
#    Updated: 2025/06/15 15:22:29 by weiyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
PATH_SRC = ./
SRC = ft_printf.c	ft_putchar.c    ft_putstr.c     ft_puthex.c ft_puthex_ptr.c     ft_putnbr.c     ft_putnbr_unsigned.c \
	ft_putptr.c 
OBJ = $(SRC:.c=.o)
PATH_HEADER = ./
all: $(NAME)
$(NAME): $(OBJ)
	ar rc $(NAME) $^
$(PATH_SRC)%.o: $(PATH_SRC)%.c
	cc $(FLAG) -I$(PATH_HEADER) -c $< -o $@ 
clean: 
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
