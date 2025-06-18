/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:17:04 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/18 12:25:26 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     ft_intlen_unsigned(unsigned int nb)
{
        int     len;

        len = 0;
        while (nb)
        {
                nb /= 10;
                len ++;
        }
        return (len);
}

char *ft_itoa_unsigned(unsigned int n)
{
        int     len;
        char    *str;

        len = ft_intlen_unsigned (n);
        str = (char *)malloc (sizeof (char) * (len + 1));
        if (!str)
                return (NULL);
        str[len] = '\0';
        if (n == 0)
                str[0] = '0';
        while (n > 0)
        {
                str[len - 1] = n % 10 + '0';
                n /= 10;
                len --;
        }
        return (str);
}

