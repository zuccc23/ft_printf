/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:27:02 by dahmane           #+#    #+#             */
/*   Updated: 2024/11/28 17:35:40 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		count;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		write (1, "-", 1);
		count++;
		nb = -nb;
	}
	if (nb > 9)
	{
		count += ft_putnbr((nb / 10));
		count += ft_nputchar((nb % 10 + '0'));
	}
	if (nb <= 9 && nb >= 0)
		count += ft_nputchar((nb % 10 + '0'));
	return (count);
}
