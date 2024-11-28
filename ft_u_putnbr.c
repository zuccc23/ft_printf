/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:26:07 by dahmane           #+#    #+#             */
/*   Updated: 2024/11/28 17:48:12 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u_putnbr(unsigned int n)
{
	int				count;
	unsigned long	nb;

	count = 0;
	nb = n;
	if (nb > 9)
	{
		count += ft_u_putnbr((nb / 10));
		count += ft_nputchar((nb % 10 + '0'));
	}
	if (nb <= 9 && nb >= 0)
		count += ft_nputchar((nb % 10 + '0'));
	return (count);
}
