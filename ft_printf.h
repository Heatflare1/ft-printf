/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:48:49 by jmeruma           #+#    #+#             */
/*   Updated: 2022/10/17 15:11:10 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef	int		(*t_func) (va_list);

int				ft_printf(char const *, ...);

int				printf_putchar(va_list arglist);
int				printf_putstr(va_list arglist);
int				printf_putnbr(va_list arglist);

#endif