/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:35:33 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/19 10:52:15 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cal_padding(char *s, t_flags flags, int *padding_spaces)
{
	int	str_len;
	int	total_len;

	str_len = ft_strlen(s);
	if (flags.precision <= str_len)
		total_len = flags.precision;
	else
		total_len = str_len;
	if (flags.width > total_len)
		*padding_spaces = flags.width - total_len;
	else
		padding_spaces = 0;
}

int	ft_putstr(char *s, t_flags flags)
{
	int	len;
	int	padding_spaces;

	cal_padding(s, flags, &padding_spaces);
	len = 0;
	if (!flags.minus)
	{
		len += put_padding(' ', padding_spaces);
		if (flags.dot)
			len += ft_putnstr_noflag(s, total_len);
		else
			len += ft_putnstr_noflag(s, -1);
	}
	else
	{
		if (flags.dot)
			len += ft_putnstr_noflag(s, total_len);
		else
			len += ft_putnstr_noflag(s, -1);
		len += put_padding (' ', padding_spaces);
	}
	return (len);
}	
				
