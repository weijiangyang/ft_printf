/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:38:57 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/22 15:50:54 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putptr_bonus(void *ptr, t_flags flags)
{
	int	count;

	if (!ptr)
		return (ft_putstr_bonus("(nil)", flags));
	count = 0;
	count += ft_puthex_ptr_bonus((unsigned long)ptr, flags);
	return (count);
}
