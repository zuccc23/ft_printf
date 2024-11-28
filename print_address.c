/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:23:49 by dahmane           #+#    #+#             */
/*   Updated: 2024/11/28 17:38:19 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_address(void *ptr)
{
	unsigned long	p;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	p = (long)ptr;
	write(1, "0x", 2);
	return (ft_putnbr_base(p, "0123456789abcdef") + 2);
}
