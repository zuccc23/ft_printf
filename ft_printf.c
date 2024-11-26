/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:30:22 by dahmane           #+#    #+#             */
/*   Updated: 2024/11/26 15:29:26 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int	ft_nputchar(char c)
{
	write(1, &c, 1);
	return (1);
}
int	ft_putnbr(int n)
{
	long	nb;
	int	count;

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
int	ft_putstr(char *s)
{
	int	n;

	n = 0;
	while (s[n])
	{
		write(1, &s[n], 1);
		n ++;
	}
	return (n);
}
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
///////////////////////////////////////////////////////////

int	check(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'c')
		return (ft_nputchar(va_arg(args, int)));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(args, int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF"));
	return (count);
}

int	ft_print(char *str, ...)
{
	va_list	args;
	int	i;
	int	count;
	
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
			count += check(str[i + 1], args);	
			i += 2;
		}
	}
	ft_nputchar('\n');
	va_end(args);
	return(count);
}

int	main(void)
{
	//printnumbers(4, "hello", "bye", "aaa", "klvnlr;va");
	//ft_print("number 1 = %d, number 2 = %d, string = %s", 14, 8, "pomme");
	printf("%d\n", ft_print("hexadec = %x, number = %d, string = %s, char = %c", 1, 14, "pomme", 'g'));
}