/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:22:26 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/22 14:35:40 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_buffer_add(t_list **lst, char *str, size_t size);

static char	*ft_printf_width(char *original, t_flags *flags)
{
	char	*padding;
	char	*new;
	int		pad_size;

	pad_size = flags->width - ft_strlen(original);
	if (pad_size <= 0)
		return (original);
	padding = ft_calloc(pad_size + 1, sizeof(char));
	if (!padding)
		return (original);
	if (flags->zero && !flags->minus)
		ft_memset(padding, '0', pad_size);
	else
		ft_memset(padding, ' ', pad_size);
	if (flags->minus)
		new = ft_strjoin(original, padding);
	else
		new = ft_strjoin(padding, original);
	free(original);
	free(padding);
	return (new);
}

void	ft_printf_str(char *str, t_flags *flags, t_list **lst)
{
	char	*new;

	if (!str)
		new = ft_strdup("(null)");
	else if (!ft_strlen(str) || (flags->precision_flag && !flags->precision))
		new = ft_strdup("");
	else
		new = ft_strdup(str);
	if (flags->width)
		new = ft_printf_width(new, flags);
	ft_printf_buffer_add(lst, new, ft_strlen(new));
	free(new);
}
