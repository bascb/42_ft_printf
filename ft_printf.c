/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:28:30 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/03 10:32:53 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* Recreation of printf by 42 */
int	ft_printf(const char *str, ...)
{
	(void) str;
	write(1,"Hi", 2);
	return (1);
}