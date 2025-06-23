/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_noflag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:45:53 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/23 09:38:30 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnstr_noflag(char *s, int n, t_flags flags)
{
	int	len;

	len = 0;
	if (!s && flags.dot && flags.precision >= 0 && flags.precision < 6)
		s = "";
	else if (!s && flags.dot && flags.precision >= 6)
		s = "(null)";
	else if (!s && !flags.dot)
		s = "(null)";
	while (*s && (n < 0 || len < n))
	{
		ft_putchar(*s++);
		len++;
	}
	return (len);
}
