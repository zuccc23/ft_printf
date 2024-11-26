/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:25:59 by dahmane           #+#    #+#             */
/*   Updated: 2024/11/26 15:15:46 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		n++;
	}
	return (n);
}
int	ft_nputchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_base(int nb, char *base)
{
	long	n;
	int	count;
	int	size;
	
	size = ft_strlen(base);
	n = nb;
	count = 0;
	if (n < 0)
	{
		//count += ft_nputchar('-');
		n *= -1;
	}
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
int	main(void)
{
	printf("\n%d\n", ft_putnbr_base(-123456, "0123456789ABCDEF"));
}