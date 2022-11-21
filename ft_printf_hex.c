/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:02:32 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/21 15:29:42 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_buffer_add(t_list **lst, char *str, size_t size);

static char	*ft_printf_cardinal_flag(int n, char *original, char c)
{
	char	*new;

	if (!n)
		return (original);
	if (c == 'x')
		new = ft_strjoin("0x", original);
	else
		new = ft_strjoin("0X", original);
	free(original);
	return (new);
}

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

void	ft_printf_hex(int n, t_flags *flags, t_list **lst, char c)
{
	char	*number;

	if (c == 'x')
		number = ft_utoa_base(n, "0123456789abcdef");
	else
		number = ft_utoa_base(n, "0123456789ABCDEF");
	if (flags->cardinal)
		number = ft_printf_cardinal_flag(n, number, c);
	if (flags->width)
		number = ft_printf_width(number, flags);
	ft_printf_buffer_add(lst, number, ft_strlen(number));
	free(number);
}
