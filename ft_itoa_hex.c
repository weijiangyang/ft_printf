/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:47:07 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/19 12:30:50 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_itoa_hex(unsigned int n, int type)
{
        int     len;
        char    *str;
        char    *base;

	if (type == 0)
        	base = "0123456789abcdef";
	if (type == 1)
		base = "0123456789ABCDEF";
        len = ft_intlen_hex(n);
        str = (char *)malloc (sizeof (char) * (len + 1));
        if (!str)
                return (NULL);
        str[len] = '\0';
        if (n == 0)
                str[0] = '0';
        while (n > 0)
        {
                str[len - 1] = base[n % 16];
                n /= 16; 
                len --; 
        }
        return (str);
}

