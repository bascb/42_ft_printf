/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:48:08 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/22 11:53:54 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_buffer_add(t_list **lst, char *str, size_t size);

static void	ft_forward_sign(char *number)
{
	char	*sign;

	if (number[0] == '0')
	{
		sign = number;
		while (*sign && *sign != '+' && *sign != '-')
			sign++;
		if (*sign == '+' || *sign == '-')
		{
			number[0] = *sign;
			*sign = '0';
		}	
	}
}

static char	*ft_printf_precision(char *original, t_flags *flags)
{
	char	*padding;
	char	*new;
	int		pad_size;

	pad_size = flags->precision - ft_strlen(original);
	if (ft_strchr(original, '+') || ft_strchr(original, '-'))
		pad_size++;
	if (pad_size <= 0)
		return (original);
	padding = ft_calloc(pad_size + 1, sizeof(char));
	if (!padding)
		return (original);
	ft_memset(padding, '0', pad_size);
	new = ft_strjoin(padding, original);
	free(original);
	free(padding);
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

void	ft_printf_uns(unsigned int n, t_flags *flags, t_list **lst)
{
	char	*number;

	(void) flags;
	number = ft_utoa(n);
	if (flags->precision)
		number = ft_printf_precision(number, flags);
	if (flags->width)
		number = ft_printf_width(number, flags);
	ft_forward_sign(number);
	ft_printf_buffer_add(lst, number, ft_strlen(number));
	free(number);
}
