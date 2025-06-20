# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weiyang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/15 14:49:34 by weiyang           #+#    #+#              #
#    Updated: 2025/06/20 15:38:38 by weiyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rc
RM          = rm -f

# Paths
HEADER      = ./
SRC_PATH    = ./
BONUS_PATH  = ./bonus/

# Files
BONUS_SRC   = ft_atoi.c ft_intlen_hex.c ft_intlen_hex_ptr.c ft_itoa.c ft_itoa_hex.c ft_itoa_hex_ptr.c \
              ft_itoa_unsigned.c ft_printf.c ft_putchar.c ft_putchar_noflag.c ft_puthex.c \
              ft_puthex_ptr.c ft_putnbr.c ft_putnbr_unsigned.c ft_putnstr_noflag.c ft_putptr.c \
              ft_putstr.c ft_putstr_noflag.c ft_strlen.c print_sign.c print_padding.c put_padding.c \
              parse_flags.c ft_intlen.c ft_intlen_unsigned.c

BONUS_SRC   = ft_bonus_flag_star.c ft_bonus_flag_minus.c  # ← Ajoute ici tes fichiers bonus

OBJ         = $(SRC:.c=.o)
BONUS_OBJ   = $(BONUS_SRC:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
	$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)

%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

%.o: $(BONUS_PATH)%.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

