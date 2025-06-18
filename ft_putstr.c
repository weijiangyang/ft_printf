/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:35:33 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/18 11:03:33 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_1(char *s)
{
	int		len;

	len = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		ft_putchar_1 (*s);
		s++;
		len++;
	}
	return (len);
}

int	ft_strlen(char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (*s)
	{
		len ++;
		s++;
	}
	return (len);
}

int	ft_printstr(char *s, int n)
{
	int	count;

	count = 0;
	if (!s)
		s = "(null)";
	while (*s && count < n)
	{
		ft_putchar_1(*s);
		count ++;
		s++;
	}
	return (count);	
}	
int	ft_putstr(char *s, t_flags flags)
{
	int	len;
	int	str_len;
	int	total_len;
	int	padding_spaces;

	str_len = ft_strlen(s);
	if (flags.precision <= str_len)
		total_len = flags.precision;
	else
		total_len = str_len;
	if (flags.width > total_len)
		padding_spaces = flags.width - total_len;
	else
		padding_spaces = 0;

	len = 0;
	if (!flags.minus)
	{
		len += put_padding(' ', padding_spaces);
		if (flags.dot)
			len += ft_printstr(s, total_len);
		else
			len += ft_putstr_1(s);
	}
	else
	{
		if (flags.dot)
			len += ft_printstr(s, total_len);
		else
			len += ft_putstr_1(s);
		len += put_padding (' ', padding_spaces);
	}
	return (len);
}	
				
