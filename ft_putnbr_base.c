/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:25:59 by dahmane           #+#    #+#             */
/*   Updated: 2024/12/11 16:41:58 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long nb, char *base)
{
	int				count;
	unsigned long	size;
	unsigned long	n;

	size = ft_strlen(base);
	n = (unsigned long)nb;
	count = 0;
	if (n < size)
	{
		count += ft_nputchar(base[n]);
	}
	if (n >= size)
	{
		count += ft_putnbr_base(n / size, base);
		count += ft_nputchar(base[n % size]);
	}
	return (count);
}
