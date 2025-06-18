/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:34:20 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/18 10:09:25 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_1(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putchar(char c, t_flags flags)
{
	int	len;

	len = 0;
	if (!flags.minus)
	{
		if (flags.width > 1)
			len += put_padding(' ', flags.width - 1);
		len += ft_putchar_1(c);
	}
	else
	{
		len += ft_putchar_1(c);
		if (flags.width > 1)
			len += put_padding(' ', flags.width - 1);
	}
	return (len);
}
