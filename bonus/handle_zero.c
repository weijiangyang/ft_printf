/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:48:49 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/22 19:01:42 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_zero(t_flags flags, char *nbr)
{
	int	len; 
	int	padding_spaces;

	len = 0;
	padding_spaces = flags.width;
	len += put_padding(' ', padding_spaces);
	free(nbr);
	return (len);
}   

