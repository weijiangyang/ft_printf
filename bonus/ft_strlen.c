/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:44:36 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/22 13:58:35 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_strlen(char *s, t_flags flags)
{
	int	len;

	if (!s && flags.dot && flags.precision >= 0 && flags.precision < 6)
		s = "";
	else if (!s && flags.dot && flags.precision >= 6)
		s = "(null)";
	else if (!s && !flags.dot)
		s = "(null)";
	len = 0;
	while (*s)
	{
		len ++;
		s++;
	}
	return (len);
}
