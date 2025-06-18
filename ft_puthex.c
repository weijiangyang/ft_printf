/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:37:30 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/18 15:49:00 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int put_padding(char c, int count)
{
        int     i;
        int     len;

        len = 0;
        i = 0;
        while (i < count)
        {
                len += ft_putchar(c);
                i++;
        }
        return (len);
}


int ft_putnbr_hex_1_maj(char *nbr, t_flags flags, int padding_zero, int padding_spaces)
{
    int len = 0;

    if (!flags.minus)
    {
        if (!flags.zero || flags.dot)
        {
            len += put_padding(' ', padding_spaces);
	    if (flags.hash && nbr[0] != '0' && nbr[0] != '\0')
		len += ft_putstr("0X");
            len += put_padding('0', padding_zero);
        }
        else
	{
	    if (flags.hash && nbr[0] != '0' && nbr[0] != '\0')
		len += ft_putstr("0X");
            len += put_padding('0', padding_spaces);
	}
        len += ft_putstr(nbr);

   }
    else
    {
	if (flags.hash && nbr[0] != '0' && nbr[0] != '\0')
		len += ft_putstr("0X");
        len += put_padding('0', padding_zero);
        len += ft_putstr(nbr);
        len += put_padding(' ', padding_spaces);
    }
    return len;
}

int ft_putnbr_hex_1_min(char *nbr, t_flags flags, int padding_zero, int padding_spaces)
{
    int len = 0;

    if (!flags.minus)
    {   
        if (!flags.zero || flags.dot)
        {
            len += put_padding(' ', padding_spaces);
            if (flags.hash && nbr[0]!= '0' && nbr[0] != '\0')
                len += ft_putstr("0x");
            len += put_padding('0', padding_zero);
        }
        else
        {
            if (flags.hash && nbr[0] != '0' && nbr[0] != '\0')
                len += ft_putstr("0x");
            len += put_padding('0', padding_spaces);
	}
            len += ft_putstr(nbr);
       
    }   
    else
    {   
        if (flags.hash &&  nbr[0] != '0' && nbr[0] != '\0')
                len += ft_putstr("0x");
        len += put_padding('0', padding_zero);
        len += ft_putstr(nbr);
        len += put_padding(' ', padding_spaces);
    }   
    return len;
}

int     ft_puthex(unsigned int n, int type, t_flags flags)
{
        char    *nbr;
        int     padding_zero;
        int     total_len;
        int     padding_spaces;
        int     len;
        int     int_len;

        len = 0;
        nbr = ft_itoa_hex(n, type);
        int_len = ft_intlen_hex(n);
        if (flags.dot && flags.precision == 0 && n == 0)
                nbr[0] = '\0';
        if (flags.precision > int_len)
                padding_zero =  flags.precision - int_len;
        else
                padding_zero = 0;
        total_len = int_len + padding_zero;
	if (flags.hash && flags.width > total_len + 2 && n != 0)
                padding_spaces = flags.width - total_len - 2;
	else if ((!flags.hash && flags.width > total_len) || n == 0)
		padding_spaces = flags.width - total_len;
        else
                padding_spaces = 0;
	if (type == 0)
        	len += ft_putnbr_hex_1_min(nbr, flags, padding_zero, padding_spaces);
	if (type == 1)
		len += ft_putnbr_hex_1_maj(nbr, flags, padding_zero, padding_spaces);

        free (nbr);
        return (len);
}

