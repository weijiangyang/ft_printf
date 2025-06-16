/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:36:03 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/16 16:44:11 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, t_flags flags)
{
	char	*nbr;
	int	padding_zero;
	int	total_len;
	int	padding_spaces;
	int	len;
	int	int_len;
	int	is_negative;

	len = 0;
	is_negative = 0;
	if (n < 0)
		is_negative = 1;
// convertir int n en char * nbr
	nbr = ft_itoa(n);
// calculate la taille de nbr
	// si n < 0,enleve 1 de intlen
	if (n < 0)
		int_len = ft_intlen(n) - 1;
	else
		int_len = ft_intlen(n);
	// si il y a .(precision) but precision est 0 et n est 0 , retourne '\0' au lieu de '0'
	if (flags.dot && flags.precision == 0 && n == 0)
		nbr[0] = '\0';
	// si la precision > int_len, le rest soit remplit par les zeros
	if (flags.precision > int_len)
		padding_zero =  flags.precision - int_len;
	else
		padding_zero = 0;
	// si n est negative ou il y a '+' ou ' ' dans le flags, il faut ajouter 1 a la precision pour avoir total_len
	if (is_negative || flags.plus || flags.space)
		total_len = int_len + padding_zero + 1;
	else
		total_len = int_len + padding_zero;
	// if flags.width > total_len, il faut ajouter les spaces pour remplir
	if (flags.width > total_len)
		padding_spaces = flags.width - total_len;
	else
		padding_spaces = 0;
	// si flags.minus n'existe pas , et flags.zero n'existe pas, remplir les padding spaces avec ' '
	if (!flags.minus && !flags.zero)
		len += put_padding(' ', padding_spaces);
	// si n est negative, affiche'-'
	if (is_negative)
		ft_putchar('-');
	// si flags.plus existe, affiche '+'
	else if (flags.plus)
		ft_putchar('+');
	// si flags.space exite, affiche ' '
	else if (flags.space)
		ft_putchar(' ');
	if (!flags.dot && flags.zero && !flags.minus)
		len += put_padding('0', padding_spaces);
	else
		len += put_padding('0', padding_zero);
	len += ft_putstr(nbr);
	if (flags.minus)
		len += put_padding (' ', padding_spaces);
	free (nbr);
	return (len); 

}
