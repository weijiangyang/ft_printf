/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:57:25 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/12 15:40:58 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putchar (char c)
{
	write (1, &c, 1);
}

int ft_atoi(char *str)
{
	int	index;
	int	sign;
	int	res;

	sign = 1;
	index = 0;
	res = 0;
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (str[index])
	{
		res = res * 10 + (str[index] - '0');
		index ++;
	}
	return (res * sign);
}

void ft_puthex(int nb)
{
    char *base = "0123456789abcdef";

    if (nb >= 16)
        ft_puthex(nb / 16);
    ft_putchar(base[nb % 16]);
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_puthex(ft_atoi(argv[1]));	
	}	
	return (0);
}
		
