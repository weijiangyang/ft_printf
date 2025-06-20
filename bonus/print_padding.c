/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:26:16 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/20 17:01:10 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_padding(int pad_zero, int pad_spaces, int is_negative, t_flags flags)
{
	int	len;

	len = 0;
	if (!flags.zero || flags.dot)
	{
		len += put_padding(' ', pad_spaces);
		len += print_sign(is_negative, flags);
		len += put_padding('0', pad_zero);
	}
	else
	{
		len += print_sign(is_negative, flags);
		len += put_padding('0', pad_spaces);
	}
	return (len);
}
