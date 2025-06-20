/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:58:15 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/20 17:00:09 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h" 

char	*ft_itoa_hex_ptr(unsigned long n)
{
	int		len;
	char	*str;
	char	*base;

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

/*int main(void)
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
}*/	
