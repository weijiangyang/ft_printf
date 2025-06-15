/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:47:25 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/15 16:15:33 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_1(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar((char)va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		len += ft_puthex (va_arg(args, unsigned int), 1);
	else if (c == 'X')
		len += ft_puthex(va_arg(args, unsigned int), 2);
	else if (c == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (c == '%')
		len += ft_putchar ('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			len += ft_printf_1(*format, args);
		}
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (len);
}
