/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:47:25 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/22 18:22:27 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_1(char c, va_list args, t_flags flags)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_bonus((char)va_arg(args, int), flags);
	else if (c == 's')
		len += ft_putstr_bonus(va_arg(args, char *), flags);
	else if (c == 'd' || c == 'i')
		len += ft_putnbr_bonus(va_arg(args, int), flags);
	else if (c == 'u')
		len += ft_putnbr_unsigned_bonus(va_arg(args, unsigned int), flags);
	else if (c == 'x')
		len += ft_puthex_bonus (va_arg(args, unsigned int), 0, flags);
	else if (c == 'X')
		len += ft_puthex_bonus(va_arg(args, unsigned int), 1, flags);
	else if (c == 'p')
		len += ft_putptr_bonus(va_arg(args, void *), flags);
	else if (c == '%')
		len += ft_putchar_bonus('%', flags);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	t_flags	flags;

	if (!format)
		return (-1);
	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			flags = (t_flags){0};
			format++;
			format = parse_flags(format, &flags, args);
			if (*format == '%')
				flags.pourcent = 1;
			len += ft_printf_1(*format, args, flags);
		}
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (len);
}
