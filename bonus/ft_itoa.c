/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:17:40 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/20 16:56:29 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nb;

	nb = n;
	len = ft_intlen(n);
	str = (char *)malloc (sizeof (char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	else if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[len - 1] = nb % 10 + '0';
		nb /= 10;
		len --;
	}
	return (str);
}
/*#include <stdio.h>

int main(void)
{
	int n;
	char *str;

	n = -42200;
	str = ft_itoa(n);
	printf("%s",str);
	return (0);
}*/
