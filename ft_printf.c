/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:30:22 by dahmane           #+#    #+#             */
/*   Updated: 2024/12/16 15:56:07 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_u_putnbr(va_arg(args, unsigned int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'c')
		return (ft_nputchar(va_arg(args, int)));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (c == 'p')
		return (print_address(va_arg(args, void *)));
	if (c == '%')
		return (ft_nputchar('%'));
	else
		return (ft_nputchar(c));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!str)
		return (-1);
	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		while (str[i] != '%' && str[i])
		{
			count += ft_nputchar(str[i]);
			i++;
		}
		if (str[i] == '%')
		{
			if (str[i + 1])
				count += check(str[i + 1], args);
			i += 2;
		}
	}
	va_end(args);
	return (count);
}
