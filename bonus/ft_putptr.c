/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:38:57 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/19 14:05:01 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr, t_flags flags)
{
	int	count;

	if (!ptr)
		return (ft_putstr_noflag("(nil)"));
	count = 0;
	count += ft_puthex_ptr((unsigned long)ptr, flags);
	return (count);
}
