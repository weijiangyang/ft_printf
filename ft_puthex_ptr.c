/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:38:25 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/15 16:22:29 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_ptr(unsigned long nb)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
		len += ft_puthex_ptr(nb / 16);
	ft_putchar(base[nb % 16]);
	return (len + 1);
}
