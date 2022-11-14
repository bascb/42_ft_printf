/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:22:26 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/14 16:09:05 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_buffer_add(t_list **lst, char *str, char c);

void	ft_printf_str(char *str, char *flags, t_list **lst)
{
	char	*new;

	(void) flags;
	new = ft_strdup(str);
	ft_printf_buffer_add(lst, new, 0);
}
