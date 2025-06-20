/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:36:03 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/20 11:49:26 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_putnbr_1(char *nbr, t_flags flags, int padding_zero, int padding_spaces)
{
	int	len;
	int	is_negative;

	len = 0;
	is_negative = 0;
	if (*nbr == '-')
	{
		is_negative = 1;
		nbr++;
	}
	if (!flags.minus)
	{
		len += print_padding(padding_zero, padding_spaces, is_negative, flags);
		len += ft_putstr_noflag(nbr);
	}
	else
	{
		len += print_sign(is_negative, flags);
		len += put_padding('0', padding_zero);
		len += ft_putstr_noflag(nbr);
		len += put_padding(' ', padding_spaces);
	}
	return (len);
}

void	cal_padding(int n, t_flags flags, int *padding_zero
	, int *padding_spaces)
{
	int	int_len;
	int	total_len;

	if (n < 0)
		int_len = ft_intlen(n) - 1;
	else
		int_len = ft_intlen(n);
	if (flags.precision > int_len)
		*padding_zero = flags.precision - int_len;
	else
		*padding_zero = 0;
	if (n < 0 || flags.plus || flags.space)
		total_len = int_len + *padding_zero + 1;
	else
		total_len = int_len + *padding_zero;
	if (flags.width > total_len)
		*padding_spaces = flags.width - total_len;
	else
		*padding_spaces = 0;
}

int	ft_putnbr(int n, t_flags flags)
{
	char	*nbr;
	int		padding_zero;
	int		padding_spaces;
	int		len;

	if (n == 0 && flags.precision == 0 && flags.dot == 1)
	{
		free (nbr);
		return (0);
	}
	len = 0;
	nbr = ft_itoa(n);
	cal_padding(n, flags, &padding_zero, &padding_spaces);
	len += ft_putnbr_1(nbr, flags, padding_zero, padding_spaces);
	free (nbr);
	return (len);
}
/*void run_test(int n, t_flags flags, const char *desc)
{
	ft_putnbr(n, flags);
	
	printf("%s", desc);
}*/

/*int main(void)
{
    t_flags f;

    // Basic no flags
    f = (t_flags){0};
    run_test(42, f, "Basic 42 with no flags");
    printf("\n");
    // Width
    f = (t_flags){.width = 10};
 printf("\n");
    run_test(42, f, "Width = 10, right aligned");

    // Width + minus
    f = (t_flags){.width = 10, .minus = 1};
 printf("\n");
    run_test(42, f, "Width = 10, left aligned");

    // Zero padding
    f = (t_flags){.width = 10, .zero = 1};
 printf("\n");
    run_test(42, f, "Zero padding (width = 10)");

    // Plus sign
    f = (t_flags){.plus = 1};
 printf("\n");
    run_test(42, f, "Plus flag (+)");

    // Space flag
    f = (t_flags){.space = 1};
 printf("\n");
    run_test(42, f, "Space flag");

    // Negative number
    f = (t_flags){.width = 10};
 printf("\n");
    run_test(-42, f, "Negative number with width");

    // Precision
    f = (t_flags){.precision = 5, .dot = 1};
 printf("\n");
    run_test(42, f, "Precision = 5");

    // Zero + precision (zero ignored)
    f = (t_flags){.width = 10, .zero = 1, .precision = 5, .dot = 1};
 printf("\n");
    run_test(42, f, "Zero + precision = 5 (zero should be ignored)");

    // Precision = 0 and n = 0
    f = (t_flags){.precision = 0, .dot = 1};
 printf("\n");
    run_test(0, f, "Precision = 0, n = 0 (should print nothing)");

    return 0;
}
*/
