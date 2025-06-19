/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:26:16 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/19 08:26:48 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_padding(int padding_zero, int padding_spaces, int is_negative, t_flags flags)
{
        int     len;

        len = 0;
        if (!flags.zero || flags.dot)
        {
            len += put_padding(' ', padding_spaces);
            len += print_sign(is_negative, flags);
            len += put_padding('0', padding_zero);
        }
        else
        {
            len += print_sign(is_negative, flags);
            len += put_padding('0', padding_spaces);
        }
        return (len);   
}
