/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:22:26 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/14 21:28:25 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_buffer_add(t_list **lst, char *str, size_t size);

void	ft_printf_str(char *str, char *flags, t_list **lst)
{
	(void) flags;
	if (!str)
		return ;
	ft_printf_buffer_add(lst, str, ft_strlen(str));
}
