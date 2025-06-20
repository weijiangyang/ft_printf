/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:40:23 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/20 11:58:03 by weiyang          ###   ########.fr       */
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

int			ft_printf(const char *format, ...);
int			ft_putchar(char c);
int			ft_puthex(unsigned int nb, int type);
int			ft_puthex_ptr(unsigned long nb);
int			ft_putnbr(int nb);
int			ft_putnbr_unsigned(unsigned int nb);
int			ft_putptr(void *ptr);
int			ft_putstr(char *s);
const char	*parse_flags(const char *format, t_flags *flags, va_list args);

#endif
