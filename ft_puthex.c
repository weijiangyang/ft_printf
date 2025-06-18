/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:37:30 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/18 12:36:54 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nb, int type)
{
	int		len;
	char	*base;

	len = 0;
	if (type == 1)
		base = "0123456789abcdef";
	if (type == 2)
		base = "0123456789ABCDEF";
	if (nb >= 16)
		len += ft_puthex(nb / 16, type);
	len += ft_putchar(base[nb % 16]);
	return (len);
}
