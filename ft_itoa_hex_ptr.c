/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:58:15 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/18 14:05:30 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

char *ft_itoa_hex_ptr(unsigned long n)
{
        int     len;
        char    *str;
	char 	*base;

	base = "0123456789abcdef";
        len = ft_intlen_hex_ptr(n);
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

int main(void)
{
	unsigned long n;
	char	*str;
	int	count;

	n = 255;
	str = ft_itoa_hex_ptr(n);
	count = ft_intlen_hex_ptr(n);
	printf("%d", count);
	printf("%s", str);
	return (0);
}	
	
