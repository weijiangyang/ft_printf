/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:38:25 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/18 14:52:47 by weiyang          ###   ########.fr       */
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


int ft_putnbr_1(char *nbr, t_flags flags, int padding_zero, int padding_spaces)
{
    int len = 0;

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
        len += ft_putstr_1(nbr);
        len += put_padding(' ', padding_spaces);
    }   
    return len;
}

int     ft_puthex_ptr(unsigned long n, t_flags flags)
{
        char    *nbr;
        int     padding_zero;
        int     total_len;
        int     padding_spaces;
        int     len;
        int     int_len;

        len = 0;
        nbr = ft_itoa_hex_ptr(n);
        int_len = ft_intlen_hex_ptr(n)i + 2;
        if (flags.dot && flags.precision == 0 && n == 0)
                nbr[0] = '\0';
        if (flags.precision > int_len)
                padding_zero =  flags.precision - int_len;
        else
                padding_zero = 0;
        total_len = int_len + padding_zero;
        if (flags.width > total_len)
                padding_spaces = flags.width - total_len;
        else
                padding_spaces = 0;
        len += ft_putnbr_1(nbr, flags, padding_zero, padding_spaces);
        free (nbr);
        return (len);
}

