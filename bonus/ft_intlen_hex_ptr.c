/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_hex_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:31:28 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/20 16:59:53 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int     ft_intlen_hex_ptr(unsigned long nb) 
{
        int     len;

        len = 0;
        if (nb == 0)
                return (1);
        while (nb)
        {
                nb /= 16; 
                len ++; 
        }
        return (len);
}


