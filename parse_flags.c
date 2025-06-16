/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:33:29 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/16 12:34:32 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char *parse_flags(const char *format, t_flags *flags, va_list args)
{
    while (*format == '-' || *format == '0' || *format == '#' ||
           *format == '+' || *format == ' ' || *format == '.' || (*format >= '0' && *format <= '9') || *format == '*')
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
        else if (*format == '.')
        {
            flags->dot = 1;
            format++;
            if (*format == '*')
                flags->precision = va_arg(args, int);
            else
                flags->precision = ft_atoi(format);
            while ((*format >= '0' && *format <= '9'))
                format++;
            continue;
        }
        else if (*format >= '0' && *format <= '9')
        {
            flags->width = ft_atoi(format);
            while (*format >= '0' && *format <= '9')
                format++;
            continue;
        }
        format++;
    }
    return format;
}

