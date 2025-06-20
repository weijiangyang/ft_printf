/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_noflag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:45:53 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/20 16:59:18 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnstr_noflag(char *s, int n)
{
	int	len;

	len = 0;
	if (!s)
		s = "(null)";
	while (*s && (n < 0 || len < n))
	{
		ft_putchar(*s++);
		len++;
	}
	return (len);
}
