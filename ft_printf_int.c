/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:32:44 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/14 21:29:06 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_buffer_add(t_list **lst, char *str, size_t size);

void	ft_printf_int(int n, char *flags, t_list **lst)
{
	char	*number;

	(void) flags;
	number = ft_itoa(n);
	ft_printf_buffer_add(lst, number, ft_strlen(number));
	free(number);
}
