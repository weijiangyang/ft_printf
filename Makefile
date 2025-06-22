# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weiyang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/15 14:49:34 by weiyang           #+#    #+#              #
#    Updated: 2025/06/22 17:00:51 by weiyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -fPIE
AR          = ar rc
RM          = rm -f

# Paths
HEADER      = ./
SRC_PATH    = ./
BONUS_PATH  = bonus/

# Files
SRC         = ft_printf.c ft_puthex.c ft_putnbr.c ft_putptr.c \
              ft_putchar.c ft_puthex_ptr.c ft_putnbr_unsigned.c ft_putstr.c

BONUS_SRC   = bonus/ft_atoi.c bonus/ft_intlen.c bonus/ft_intlen_hex.c bonus/ft_intlen_hex_ptr.c \
              bonus/ft_intlen_unsigned.c bonus/ft_itoa.c bonus/ft_itoa_hex.c bonus/ft_itoa_hex_ptr.c \
              bonus/ft_itoa_unsigned.c bonus/ft_putchar_bonus.c bonus/ft_puthex_bonus.c \
              bonus/ft_puthex_ptr_bonus.c bonus/ft_putnbr_bonus.c bonus/ft_putnbr_unsigned_bonus.c \
              bonus/ft_putnstr_noflag.c bonus/ft_putptr_bonus.c bonus/ft_putstr_bonus.c \
              bonus/ft_strlen.c bonus/parse_flags.c bonus/print_padding.c \
              bonus/print_sign.c bonus/put_padding.c

OBJ         = $(SRC:.c=.o)
BONUS_OBJ   = $(BONUS_SRC:.c=.o)

# Rules
all: $(NAME)
bonus: $(OBJ) $(BONUS_OBJ)
	$(AR) $(NAME) $(OBJ) $(BONUS_OBJ) 

$(NAME): $(OBJ) $(BONUS_OBJ)
	$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

