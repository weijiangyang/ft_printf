/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:34:20 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/20 16:56:45 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar_bonus(char c, t_flags flags)
{
	int	len;

	len = 0;
	if (!flags.minus)
	{
		if (flags.width > 1)
			len += put_padding(' ', flags.width - 1);
		len += ft_putchar(c);
	}
	else
	{
		len += ft_putchar(c);
		if (flags.width > 1)
			len += put_padding(' ', flags.width - 1);
	}
	return (len);
}
