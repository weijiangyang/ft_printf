/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:38:25 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/20 11:40:31 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_right(char *nbr, t_flags flags, int padding_zero
	, int padding_spaces)
{
	int	len;

	len = 0;
	if (!flags.zero || flags.dot)
	{
		len += put_padding(' ', padding_spaces);
		len += ft_putstr_noflag("0x");
		len += put_padding('0', padding_zero);
	}
	else
	{
		len += ft_putstr_noflag("0x");
		len += put_padding('0', padding_spaces);
	}
	len += ft_putstr_noflag(nbr);
	return (len);
}

int	ft_puthex_ptr_1(char *nbr, t_flags flags, int padding_zero
	, int padding_spaces)
{
	int	len;

	len = 0;
	if (!flags.minus)
		len += ft_putptr_right(nbr, flags, padding_zero, padding_spaces);
	else
	{
		len += ft_putstr_noflag("0x");
		len += put_padding('0', padding_zero);
		len += ft_putstr_noflag(nbr);
		len += put_padding(' ', padding_spaces);
	}
	return (len);
}

void	cal_padding(unsigned long n, t_flags flags, int *padding_zero
	, int *padding_spaces)
{
	int	int_len;
	int	total_len;

	int_len = ft_intlen_hex_ptr(n);
	if (flags.precision > int_len)
		*padding_zero = flags.precision - int_len;
	else
		*padding_zero = 0;
	total_len = int_len + padding_zero + 2;
	if (flags.width > total_len)
		*padding_spaces = flags.width - total_len;
	else
		*padding_spaces = 0;
}

int	ft_puthex_ptr(unsigned long n, t_flags flags)
{
	char	*nbr;
	int		padding_zero;
	int		padding_spaces;
	int		len;

	len = 0;
	nbr = ft_itoa_hex_ptr(n);
	if (!nbr)
		return (0);
	if (flags.dot && flags.precision == 0 && n == 0)
	{
		free (nbr);
		return (ft_putstr_noflag("0x"));
	}
	cal_padding(n, flags, &padding_zero, &padding_spaces);
	len += ft_puthex_ptr_1(nbr, flags, padding_zero, padding_spaces);
	free (nbr);
	return (len);
}
