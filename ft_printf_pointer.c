/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:01:01 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/21 12:00:03 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_buffer_add(t_list **lst, char *str, size_t size);

void	ft_printf_pointer(unsigned long int n, t_flags *flags, t_list **lst)
{
	char	*header;
	char	*number;

	(void) flags;
	if (!n)
	{
		header = ft_calloc(6, sizeof(char));
		if (!header)
			return ;
		ft_strlcpy(header, "(nil)", 6);
		ft_printf_buffer_add(lst, header, 5);
		free(header);
		return ;
	}
	header = ft_calloc(3, sizeof(char));
	if (!header)
		return ;
	ft_strlcpy(header, "0x", 3);
	ft_printf_buffer_add(lst, header, 2);
	free(header);
	number = ft_ultoa_base(n, "0123456789abcdef");
	ft_printf_buffer_add(lst, number, ft_strlen(number));
	free(number);
}
