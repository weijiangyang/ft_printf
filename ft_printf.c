/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:47:25 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/13 19:02:56 by weijiangyang     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*int ft_printf(const char *format,...)
{
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
	
int ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		s = "(null)";
		
	while (*s)
	{
		ft_putchar (*s);
		s++;
		len++;
	}
	return (len);
}

int	 ft_puthex(unsigned int  nb, int type) 
{
	int	len;
	char	*base;

	len = 0;
	if (type == 1)
		base = "0123456789abcdef";
	if (type == 2)
		base = "0123456789ABCDEF";
	if (nb >= 16) 
	{
		ft_puthex(nb / 16, type);
		len ++;
	}
	ft_putchar(base[nb % 16]);
	return (len + 1);
}

int	ft_puthex_ptr(unsigned long nb)
{
	int	len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_puthex_ptr(nb / 16);
		len++；
	}
	ft_putchar(base[nb % 16]);
	return (len + 1);
}
	
int main(void)
{
	/*ft_putstr("hello \n");
	ft_putstr(NULL);*/
	int	len;

	len = ft_puthex(42, 1);
	printf("%d", len);
	return (0);
}

int ft_putptr(void *ptr)
{
	int	count;
	
	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	count += ft_putstr('0x');
	count += ft_puthex_ptr((unsigned long)ptr);
	return (count);
}

	
int ft_printf(const char *format, ...)
{
	va_list	args;
	va_start(args, *format);
	int	len;

	len = 0;
	while (*format)
	{
		if (*format == "%" && *(format + 1))
			format++;
			if (*format == 'c')
				len+= ft_putstr(va_arg(args, char);		
			else if (*format == 's')
				len+= ft_putstr(va_arg(args, char *);
			else if (*format == 'd' || *format = 'i')
				len+= ft_putstr(va_arg(args, int);
			else if (*format == 'u')
				len+= ft_putstr(va_arg(args, unsigned int);
			else if (*format == 'x')
				len+ = ft_puthex(va_arg(args,unsigned int), 1);
			else if (*format == 'X')
				len+= ft_puthex(va_arg(args, unsigned int), 2);
		 	else if (*format == 'p')
				len+= ft_putptr(va_arg(args, void *));
			else if (*format =='%')
				len+=ft_putchar ('%');
	}
}
