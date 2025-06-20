/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:36:40 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/20 16:57:18 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_unsigned_1_bonus(char *nbr, t_flags flags, int padding_zero
	, int padding_spaces)
{
	int	len;

	len = 0;
	if (!flags.minus)
	{
		if (!flags.zero || flags.dot)
		{
			len += put_padding(' ', padding_spaces);
			len += put_padding('0', padding_zero);
		}
		else
			len += put_padding('0', padding_spaces);
		len += ft_putstr(nbr);
	}
	else
	{
		len += put_padding('0', padding_zero);
		len += ft_putstr(nbr);
		len += put_padding(' ', padding_spaces);
	}
	return (len);
}

void	cal_padding_unsigned(unsigned int n, t_flags flags, int *padding_zero
	, int *padding_spaces)
{
	int	int_len;
	int	total_len;

	int_len = ft_intlen_unsigned(n);
	if (flags.precision > int_len)
		*padding_zero = flags.precision - int_len;
	else
		*padding_zero = 0;
	total_len = int_len + *padding_zero;
	if (flags.width > total_len)
		*padding_spaces = flags.width - total_len;
	else
		*padding_spaces = 0;
}

int	ft_putnbr_unsigned_bonus(unsigned int n, t_flags flags)
{
	char	*nbr;
	int		padding_zero;
	int		padding_spaces;
	int		len;

	len = 0;
	nbr = ft_itoa_unsigned(n);
	if (!nbr)
		return (0);
	if (flags.dot && flags.precision == 0 && n == 0)
	{
		free (nbr);
		return (0);
	}
	cal_padding_unsigned(n, flags, &padding_zero, &padding_spaces);
	len += ft_putnbr_unsigned_1_bonus(nbr, flags, padding_zero, padding_spaces);
	free (nbr);
	return (len);
}
