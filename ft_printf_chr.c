/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:16:44 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/14 20:59:31 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_buffer_add(t_list **lst, char *str, size_t size);

void	ft_printf_chr(char c, char *flags, t_list **lst)
{	
	(void) flags;
	ft_printf_buffer_add(lst, &c, 1);
}
