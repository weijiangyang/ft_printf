/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:34:20 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/19 08:16:20 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_flags flags)
{
	int	len;

	len = 0;
	if (!flags.minus)
	{
		if (flags.width > 1)
			len += put_padding(' ', flags.width - 1);
		len += ft_putchar_noflag(c);
	}
	else
	{
		len += ft_putchar_noflag(c);
		if (flags.width > 1)
			len += put_padding(' ', flags.width - 1);
	}
	return (len);
}
