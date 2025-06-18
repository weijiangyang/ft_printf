/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:36:03 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/18 16:29:42 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int put_padding(char c, int count)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i < count)
	{
		len += ft_putchar(c);
		i++;
	}
	return (len);
}

int print_sign(int is_negative, t_flags flags) {
    if (is_negative)
        return ft_putchar('-');
    if (flags.plus)
        return ft_putchar('+');
    if (flags.space)
        return ft_putchar(' ');
    return 0;
}

int print_padding(int padding_zero, int padding_spaces, int is_negative, t_flags flags)
{
	int	len;

	len = 0;
	if (!flags.zero || flags.dot)
        {
            len += put_padding(' ', padding_spaces);
            len += print_sign(is_negative, flags);
            len += put_padding('0', padding_zero);
        }
        else
        {
            len += print_sign(is_negative, flags);
            len += put_padding('0', padding_spaces);
        }
	return (len);   
}

int ft_putnbr_1(char *nbr, t_flags flags, int padding_zero, int padding_spaces)
{
    int len = 0;
    int is_negative = 0;

    if (*nbr == '-')
    {
        is_negative = 1;
        nbr++;
    }

    if (!flags.minus)
    {
     	len += print_padding(padding_zero, padding_spaces, is_negative, flags);
        len += ft_putstr(nbr);
    }
    else
    {
	len += print_sign(is_negative, flags);
        len += put_padding('0', padding_zero);
        len += ft_putstr(nbr);
        len += put_padding(' ', padding_spaces);
    }
    return (len);
}

void cal_padding(int n, t_flags flags, int *padding_zero, int *padding_spaces)
{
	int	int_len;
	int	total_len;
	
        if (n < 0)
                int_len = ft_intlen(n) - 1;
        else
                int_len = ft_intlen(n);
        if (flags.precision > int_len)
               *padding_zero =  flags.precision - int_len;
        else
                *padding_zero = 0;
        if (n < 0 || flags.plus || flags.space)
                total_len = int_len + *padding_zero + 1;
        else
                total_len = int_len + *padding_zero;
        if (flags.width > total_len)
                *padding_spaces = flags.width - total_len;
        else
                *padding_spaces = 0;
}
	
int	ft_putnbr(int n, t_flags flags)
{
	char	*nbr;
	int	padding_zero;
	int	padding_spaces;
	int	len;

	len = 0;
	nbr = ft_itoa(n);
	cal_padding(n, flags, &padding_zero, &padding_spaces);
	len += ft_putnbr_1(nbr, flags, padding_zero, padding_spaces);
	free (nbr);
	return (len); 
}
