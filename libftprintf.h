/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:24:08 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/21 16:27:20 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_flags
{
	int				plus;
	int				space;
	int				cardinal;
	int				minus;
	int				zero;
	int				width;
	int				precision;
	int				length;
}					t_flags;

/* Recreation of printf by 42 */
int	ft_printf(const char *format, ...)
	__attribute__((format(printf, 1, 2)));

#endif
