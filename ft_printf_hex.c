/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:02:32 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/14 17:17:09 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_buffer_add(t_list **lst, char *str, char c);

void	ft_printf_hex(int n, char *flags, t_list **lst, char c)
{
	(void) flags;
	if (c == 'x')
		ft_printf_buffer_add(lst, ft_utoa_base(n, "0123456789abcdef"), 0);
	else
		ft_printf_buffer_add(lst, ft_utoa_base(n, "0123456789ABCDEF"), 0);
}
