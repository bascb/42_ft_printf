/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:02:32 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/14 21:29:32 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_buffer_add(t_list **lst, char *str, size_t size);

static void	ft_printf_cardinal_flag(int n, t_list **lst, char c)
{
	if (!n)
		return ;
	if (c == 'x')
		ft_printf_buffer_add(lst, "0x", 2);
	else
		ft_printf_buffer_add(lst, "0X", 2);
}

void	ft_printf_hex(int n, char *flags, t_list **lst, char c)
{
	char	*number;

	if (ft_charinset('#', flags))
		ft_printf_cardinal_flag(n, lst, c);
	if (c == 'x')
		number = ft_utoa_base(n, "0123456789abcdef");
	else
		number = ft_utoa_base(n, "0123456789ABCDEF");
	ft_printf_buffer_add(lst, number, ft_strlen(number));
	free(number);
}
