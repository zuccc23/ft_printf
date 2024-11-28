/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:46:45 by dahmane           #+#    #+#             */
/*   Updated: 2024/11/28 18:05:32 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_nputchar(char c);
int	ft_putnbr(int n);
int	ft_u_putnbr(unsigned int n);
int	ft_putstr(char *s);
int	ft_strlen(char *str);
int	ft_putnbr_base(unsigned long nb, char *base);
int	print_address(void *ptr);
int	ft_printf(const char *str, ...);

#endif