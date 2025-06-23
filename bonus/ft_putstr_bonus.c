/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:35:33 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/23 09:45:28 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	cal_padding_str(char *s, t_flags flags, int *padding_spaces)
{
	int	str_len;
	int	total_len;

	str_len = ft_strlen(s, flags);
	if (flags.dot && flags.precision <= str_len)
		total_len = flags.precision;
	else
		total_len = str_len;
	if (flags.width > total_len)
		*padding_spaces = flags.width - total_len;
	else
		*padding_spaces = 0;
}

char	*handle_null(char *s, t_flags flags)
{
	if (!s && flags.dot && flags.precision >= 0 && flags.precision < 6)
		s = "";
	else if (!s && flags.dot && flags.precision >= 6)
		s = "(null)";
	else if (!s && !flags.dot)
		s = "(null)";
	return (s);
}

int	ft_putstr_bonus(char *s, t_flags flags)
{
	int	len;
	int	padding_spaces;

	cal_padding_str(s, flags, &padding_spaces);
	len = 0;
	handle_null(s, flags);
	if (!flags.minus)
	{
		len += put_padding(' ', padding_spaces);
		if (flags.dot)
			len += ft_putnstr_noflag(s, flags.precision, flags);
		else
			len += ft_putnstr_noflag(s, -1, flags);
	}
	else
	{
		if (flags.dot)
			len += ft_putnstr_noflag(s, flags.precision, flags);
		else
			len += ft_putnstr_noflag(s, -1, flags);
		len += put_padding (' ', padding_spaces);
	}
	return (len);
}	
