/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:32:44 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/14 16:12:12 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_buffer_add(t_list **lst, char *str, char c);

void	ft_printf_int(int n, char *flags, t_list **lst)
{
	(void) flags;
	ft_printf_buffer_add(lst, ft_itoa(n), 0);
}
