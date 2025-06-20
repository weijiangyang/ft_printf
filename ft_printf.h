/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:40:23 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/20 14:02:37 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int	dot;
	int	hash;
	int	plus;
	int	space;
}	t_flags;

typedef struct s_padding
{
	int	spaces;
	int	zero;
}	t_padding;

int			ft_atoi(char *s);
int			ft_intlen_hex(unsigned int nb);
char		*ft_itoa(int n);
char		*ft_itoa_hex(unsigned int n, int type);
char		*ft_itoa_hex_ptr(unsigned long n);
char		*ft_itoa_unsigned(unsigned int n);
int			ft_printf(const char *format, ...);
int			ft_putchar(char c, t_flags flags);
int			ft_putchar_noflag(char c);
int			ft_puthex(unsigned int n, int type, t_flags flags);
int			ft_puthex_ptr(unsigned long n, t_flags flags);
int			ft_putnbr(int n, t_flags flags);
int			ft_putnbr_unsigned(unsigned int n, t_flags flags);
int			ft_putnstr_noflag(char *s, int n);
int			ft_putptr(void *ptr, t_flags flags);
int			ft_putstr(char *s, t_flags flags);
int			ft_putstr_noflag(char *s);
int			ft_strlen(char *s);
int			print_padding(int pad_zero, int pad_spaces, int is_negative,
				t_flags flags);
int			print_sign(int is_negative, t_flags flags);
int			put_padding(char c, int count);
const char	*parse_flags(const char *format, t_flags *flags, va_list args);

#endif
