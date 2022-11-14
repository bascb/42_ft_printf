/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:40:18 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/14 12:00:43 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_printf_buffer_size(t_list **lst)
{
	size_t	size;
	t_list	*next;

	size = 0;
	next = *lst;
	while (next)
	{
		size += ft_strlen(next->content);
		next = next->next;
	}
	return (size);
}

void	ft_printf_buffer_add(t_list **lst, char *str, char c)
{
	char	*c_to_str;

	if (str)
		ft_lstadd_back(lst, ft_lstnew(str));
	if (c)
	{
		c_to_str = ft_calloc(2, sizeof(char));
		if (!c_to_str)
			return ;
		c_to_str[0] = c;
		ft_lstadd_back(lst, ft_lstnew(c_to_str));
	}
}

int	ft_printf_buffer_output(t_list **lst)
{
	size_t	buff_size;
	char	*buffer;
	t_list	*next;

	buff_size = ft_printf_buffer_size(lst);
	buffer = ft_calloc(buff_size + 1, sizeof(char));
	if (!buffer)
	{
		ft_lstclear(lst, free);
		return (-1);
	}
	next = *lst;
	while (next)
	{
		ft_strlcat(buffer, next->content, buff_size + 1);
		next = next->next;
	}
	ft_putstr_fd(buffer, 1);
	ft_lstclear(lst, free);
	free(buffer);
	return ((int) buff_size);
}
