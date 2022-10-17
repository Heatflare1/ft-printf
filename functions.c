/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:41:07 by jmeruma           #+#    #+#             */
/*   Updated: 2022/10/17 15:46:36 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putchar(va_list arglist)
{
	char c;
	
	c = va_arg(arglist, int);
	write(1, &c, 1);
	return (1);
}

int printf_putstr(va_list arglist)
{
	char	*s;
	
	s = va_arg(arglist, char *);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int printf_putnbr(va_list arglist)
{
	int		nb;
	char	*s;

	nb = va_arg(arglist, int);
	s = ft_itoa(nb);
	ft_putstr_fd(s, 1);
	nb = ft_strlen(s);
	free(s);
	return (nb);
}