/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:24:08 by bcastelo          #+#    #+#             */
/*   Updated: 2023/06/11 17:16:21 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
	int				precision_flag;
	int				precision;
	int				length;
}					t_flags;

/* Recreation of printf by 42 */
int	ft_printf(const char *format, ...)
	__attribute__((format(printf, 1, 2)));

#endif
