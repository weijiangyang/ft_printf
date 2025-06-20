/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:44:11 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/20 16:54:09 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int     ft_intlen_unsigned(unsigned int nb) 
{
        int     len;

        len = 0;
	if (nb == 0)
		return (1);
        while (nb)
        {
                nb /= 10; 
                len ++; 
        }
        return (len);
}

