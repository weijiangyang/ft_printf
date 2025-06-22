/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:40:23 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/22 13:46:04 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flags
{
        int     minus;
        int     zero;
        int     width;
        int     precision;
        int     dot;
        int     hash;
        int     plus;
        int     space;
}       t_flags;

typedef struct s_padding
{
        int     spaces;
        int     zero;
}       t_padding;
int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_puthex(unsigned int nb, int type);
int	ft_puthex_ptr(unsigned long nb);
int	ft_putnbr(int nb);
int	ft_putnbr_unsigned(unsigned int nb);
int	ft_putptr(void *ptr);
int	ft_putstr(char *s);

int                     ft_atoi(const char *s);
int                     ft_intlen(int nb);
int                     ft_intlen_hex(unsigned int nb);
int                     ft_intlen_hex_ptr(unsigned long nb);
int                     ft_intlen_unsigned(unsigned int nb);
char            *ft_itoa(int n);
char            *ft_itoa_hex(unsigned int n, int type);
char            *ft_itoa_hex_ptr(unsigned long n);
char            *ft_itoa_unsigned(unsigned int n);
int                     ft_putchar_bonus(char c, t_flags flags);
int                     ft_puthex_bonus(unsigned int n, int type, t_flags flags);
int                     ft_puthex_ptr_bonus(unsigned long n, t_flags flags);
int                     ft_putnbr_bonus(int n, t_flags flags);
int                     ft_putnbr_unsigned_bonus(unsigned int n, t_flags flags);
int                     ft_putnstr_noflag(char *s, int n, t_flags flags);
int                     ft_putptr_bonus(void *ptr, t_flags flags);
int                     ft_putstr_bonus(char *s, t_flags flags);
int                     ft_strlen(char *s, t_flags flags);
int                     print_padding(int pad_zero, int pad_spaces, int is_negative,
                                t_flags flags);
int                     print_sign(int is_negative, t_flags flags);
int                     put_padding(char c, int count);
const char      *parse_flags(const char *format, t_flags *flags, va_list args);

#endif
