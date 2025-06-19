/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:23:18 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/19 08:24:00 by weiyang          ###   ########.fr       */
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
                len += ft_putchar_noflag(c);
                i++;
        }
        return (len);
}

