/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_noflag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:10:15 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/20 14:21:05 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_noflag(char *s)
{
	int	len;

	len = 0;
	if (!s)
		s = "(nil)";
	while (*s)
	{
		len += ft_putchar_noflag(*s);
		s++;
	}
	return (len);
}
