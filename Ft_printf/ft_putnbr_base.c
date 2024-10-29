/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:06:59 by espinell          #+#    #+#             */
/*   Updated: 2023/11/09 11:42:10 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	intcount(int nb)
{
	size_t	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	if (nb == 0)
		return (0);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	ft_hexa_low(unsigned int nb)
{
	char	result[30];
	char	*base;
	int		i;
	int		x;

	base = "0123456789abcdef";
	i = 0;
	x = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	while (nb > 0)
	{
		result[i++] = base[(nb % 16)];
		nb /= 16;
	}
	while (i > 0)
	{
		ft_putchar(result[--i]);
		x++;
	}
	return (x);
}

int	ft_hexa_upp(unsigned int nb)
{
	char	result[30];
	char	*base;
	int		i;
	int		x;

	base = "0123456789ABCDEF";
	i = 0;
	x = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	while (nb > 0)
	{
		result[i++] = base[(nb % 16)];
		nb /= 16;
	}
	while (i > 0)
	{
		ft_putchar(result[--i]);
		x++;
	}
	return (x);
}

int	ft_hexa_ptr(void *ptr)
{
	char		result[30];
	char		*base;
	uintptr_t	nb;
	int			i;
	int			x;

	nb = (uintptr_t)ptr;
	base = "0123456789abcdef";
	i = 0;
	x = 0;
	if (!ptr)
		return (write (1, "(nil)", 5));
	else
		write (1, "0x", 2);
	while (nb > 0)
	{
		result[i++] = base[(nb % 16)];
		nb /= 16;
	}
	while (i > 0)
	{
		ft_putchar(result[--i]);
		x++;
	}
	return (x + 2);
}
