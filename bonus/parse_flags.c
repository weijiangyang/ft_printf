/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:33:29 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/20 16:59:36 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

const char	*parse_flags_dot(const char *format, t_flags *flags, va_list args)
{
	flags->dot = 1;
	format++;
	if (*format == '*')
	{
		flags -> precision = va_arg(args, int);
		if (flags -> precision < 0)
			flags->dot = 0;
		format++;
	}
	else
	{
		flags -> precision = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
			format++;
	}
	return (format);
}

const char	*parse_flags_1(const char *format, t_flags *flags)
{
	if (*format == '-')
		flags->minus = 1;
	else if (*format == '0')
		flags->zero = 1;
	else if (*format == '#')
		flags->hash = 1;
	else if (*format == '+')
		flags->plus = 1;
	else if (*format == ' ')
		flags->space = 1;
	format++;
	return (format);
}

void	sanitize_flags(t_flags *flags)
{
	if (flags->minus)
		flags->zero = 0;
	if (flags->plus)
		flags->space = 0;
	if (flags->dot)
		flags->zero = 0;
}

const char	*parse_flags_width(const char *format, t_flags *flags)
{
	flags -> width = ft_atoi(format);
	while (*format >= '0' && *format <= '9')
		format++;
	return (format);
}

const char	*parse_flags(const char *format, t_flags *flags, va_list args)
{
	while (*format == '-' || *format == '0' || *format == '#' || *format == '+'
		|| *format == ' ' || *format == '.'
		|| (*format >= '0' && *format <= '9') || *format == '*')
	{
		if (*format == '-' || *format == '0' || *format == '#' || *format == '+'
			|| *format == ' ')
			format = parse_flags_1(format, flags);
		else if (*format == '.')
			format = parse_flags_dot(format, flags, args);
		else if (*format == '*')
		{
			flags->width = va_arg(args, int);
			format++;
		}
		else if (*format >= '0' && *format <= '9')
			format = parse_flags_width(format, flags);
	}
	sanitize_flags(flags);
	return (format);
}
