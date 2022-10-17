/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:41:25 by jmeruma           #+#    #+#             */
/*   Updated: 2022/10/17 15:38:36 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_func function_list[128] = {
['c'] = &printf_putchar,
['s'] = &printf_putstr,
['d'] = &printf_putnbr
};

int	ft_printf(char const *format, ...)
{
	int i;
	int len;
	va_list arglist;
	
	va_start(arglist, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += (*function_list[(int)format[i]])(arglist);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			len++;
		}
		i++;
	}
	va_end(arglist);
	return (len);
}
