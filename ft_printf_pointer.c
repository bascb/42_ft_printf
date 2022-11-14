/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:01:01 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/14 18:20:00 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_buffer_add(t_list **lst, char *str, char c);

void	ft_printf_pointer(unsigned long int n, char *flags, t_list **lst)
{
	char	*header;
	
	(void) flags;
	header = ft_calloc(3, sizeof(char));
	if (!header)
		return ;
	ft_strlcpy(header, "0x", 3);
	ft_printf_buffer_add(lst, header, 0);
	ft_printf_buffer_add(lst, ft_ultoa_base(n, "0123456789abcdef"), 0);
}