/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:28:30 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/14 22:00:25 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_buffer_add(t_list **lst, char *str, size_t size);

int		ft_printf_buffer_output(t_list **lst);

void	ft_printf_str(char *str, char *flags, t_list **lst);

void	ft_printf_chr(char c, char *flags, t_list **lst);

void	ft_printf_int(int n, char *flags, t_list **lst);

void	ft_printf_uns(unsigned int n, char *flags, t_list **lst);

void	ft_printf_hex(int n, char *flags, t_list **lst, char c);

void	ft_printf_pointer(unsigned long int n, char *flags, t_list **lst);

static char	*ft_get_flags(char *f)
{
	char	*end;
	char	*flags_set;
	char	*flags;

	flags_set = "-0.# +123456789";
	end = f;
	while (ft_charinset(*end, flags_set))
		end++;
	flags = ft_calloc(end - f + 1, sizeof(char));
	if (!flags)
		return (NULL);
	ft_strlcpy(flags, f, end - f + 1);
	return (flags);
}

static char	*ft_print_conversion(char *f, t_list **lst, va_list	arguments)
{
	char	*flags;
	int		f_size;

	flags = ft_get_flags(f + 1);
	f_size = ft_strlen(flags);
	if (*(f + 1 + f_size) == 's')
		ft_printf_str(va_arg(arguments, char *), flags, lst);
	if (*(f + 1 + f_size) == 'c')
		ft_printf_chr(va_arg(arguments, int), flags, lst);
	if (*(f + 1 + f_size) == 'i' || *(f + 1 + f_size) == 'd')
		ft_printf_int(va_arg(arguments, int), flags, lst);
	if (*(f + 1 + f_size) == 'u')
		ft_printf_uns(va_arg(arguments, unsigned int), flags, lst);
	if (*(f + 1 + f_size) == 'x' || *(f + 1 + f_size) == 'X')
		ft_printf_hex(va_arg(arguments, int), flags, lst, *(f + 1 + f_size));
	if (*(f + 1 + f_size) == 'p')
		ft_printf_pointer(va_arg(arguments, unsigned long int), flags, lst);
	free(flags);
	return (f + 2 + f_size);
}

/* Recreation of printf by 42 */
int	ft_printf(const char *format, ...)
{
	t_list	**buffer_lst;
	char	*f;
	va_list	arguments;

	va_start(arguments, format);
	buffer_lst = ft_calloc(1, sizeof(t_list *));
	if (!buffer_lst)
		return (-1);
	f = (char *) format;
	while (*f)
	{
		if (*f == '%' && *(f + 1) != '%')
			f = ft_print_conversion(f, buffer_lst, arguments);
		else
		{
			ft_printf_buffer_add(buffer_lst, f, 1);
			if (*f == '%')
				f++;
			f++;
		}
	}
	va_end(arguments);
	return ((int) ft_printf_buffer_output(buffer_lst));
}
