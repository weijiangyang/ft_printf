/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:24:31 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/19 08:25:06 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_sign(int is_negative, t_flags flags)
{
    if (is_negative)
        return ft_putchar_noflag('-');
    if (flags.plus)
        return ft_putchar_noflag('+');
    if (flags.space)
        return ft_putchar_noflag(' ');
    return 0;
}
