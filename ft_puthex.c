/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:37:30 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/20 14:14:35 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_1_right(char *nbr, t_flags flags, t_padding paddings, int type)
{
	int	len;

	len = 0;
	if (!flags.zero || flags.dot)
	{
		len += put_padding(' ', paddings.spaces);
		if (flags.hash && nbr[0] != '0' && nbr[0] != '\0' && type == 1)
		len += ft_putstr_noflag("0X");
		if (flags.hash && nbr[0] != '0' && nbr[0] != '\0' && type == 0)
		len += ft_putstr_noflag("0x");
		len += put_padding('0', paddings.zero);
	}
	else
	{
		if (flags.hash && nbr[0] != '0' && nbr[0] != '\0' && type == 1)
			len += ft_putstr_noflag("0X");
		if (flags.hash && nbr[0] != '0' && nbr[0] != '\0' && type == 0)
			len += ft_putstr_noflag("0x");
		len += put_padding('0', paddings.spaces);
	}
	len += ft_putstr_noflag(nbr);
	return (len);
}	

int	ft_puthex_1(char *nbr, t_flags flags, t_padding paddings, int type)
{
	int	len;

	len = 0;
	if (!flags.minus)
		len += ft_puthex_1_right(nbr, flags, paddings, type);
	else
	{
		if (flags.hash && nbr[0] != '0' && nbr[0] != '\0' && type == 1)
			len += ft_putstr_noflag("0X");
		if (flags.hash && nbr[0] != '0' && nbr[0] != '\0' && type == 0)
			len += ft_putstr_noflag("0x");
		len += put_padding('0', paddings.zero);
		len += ft_putstr_noflag(nbr);
		len += put_padding(' ', paddings.spaces);
	}
	return (len);
}

void	cal_padding(unsigned int n, t_flags flags, t_padding *paddings)
{
	int	int_len;
	int	total_len;

	int_len = ft_intlen_hex(n);
	if (flags.precision > int_len)
		paddings->zero = flags.precision - int_len;
	else
		paddings->zero = 0;
	total_len = int_len + paddings->zero;
	if (flags.hash && flags.width > total_len + 2 && n != 0)
		paddings->spaces = flags.width - total_len - 2;
	else if ((!flags.hash && flags.width > total_len) || n == 0)
		paddings->spaces = flags.width - total_len;
	else
		paddings->spaces = 0;
}

int	ft_puthex(unsigned int n, int type, t_flags flags)
{
	char		*nbr;
	int			len;
	t_padding	paddings;

	len = 0;
	nbr = ft_itoa_hex(n, type);
	if (!nbr)
		return (0);
	if (flags.dot && flags.precision == 0 && n == 0)
	{
		free (nbr);
		return (0);
	}
	cal_padding(n, flags, &paddings);
	len += ft_puthex_1(nbr, flags, paddings, type);
	free (nbr);
	return (len);
}
