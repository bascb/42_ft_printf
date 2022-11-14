/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:48:08 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/14 21:29:20 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_buffer_add(t_list **lst, char *str, size_t size);

void	ft_printf_uns(unsigned int n, char *flags, t_list **lst)
{
	char	*number;

	(void) flags;
	number = ft_utoa(n);
	ft_printf_buffer_add(lst, number, ft_strlen(number));
	free(number);
}
