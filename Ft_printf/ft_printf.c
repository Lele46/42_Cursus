/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:19:35 by espinell          #+#    #+#             */
/*   Updated: 2023/10/27 14:06:25 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"	

int	ft_form(const char type, va_list args)
{
	int	size_tot;

	size_tot = 0;
	if (type == 'i' || type == 'd')
		size_tot += ft_itoa(va_arg(args, int));
	else if (type == 'u')
		size_tot += ft_unsitoa(va_arg(args, unsigned int));
	else if (type == 's')
		size_tot += ft_putstr(va_arg(args, char *));
	else if (type == 'c')
		size_tot += ft_putchar(va_arg(args, int));
	else if (type == 'x')
		size_tot += ft_hexa_low(va_arg(args, int));
	else if (type == 'X')
		size_tot += ft_hexa_upp(va_arg(args, int));
	else if (type == 'p')
		size_tot += ft_hexa_ptr(va_arg(args, void *));
	else if (type == '%')
	{
		write(1, "%", 1);
		size_tot++;
	}
	return (size_tot);
}

int	ft_printf(const char *type, ...)
{
	va_list	args;
	int		x;
	int		size_tot;

	x = 0;
	size_tot = 0;
	va_start(args, type);
	while (type[x])
	{
		if (type[x] == '%')
		{
			x++;
			size_tot += ft_form(type[x], args);
		}
		else
		{
			ft_putchar(type[x]);
			size_tot++;
		}
		x++;
	}
	return (size_tot);
	va_end(args);
}

/*int main()
{
	int i = 1234;
	
	int size_tot;
	
	size_tot = printf("%i", i);
	
	ft_printf("%i\n", size_tot);
}*/
/*int main()
{
    int i = -5;
    unsigned int u = 430;
    char *s = "hello";
    char c = 'A';
    unsigned int x = 123;
    void *p = NULL;
    int size_tot;
    int size_tot_ft;

    // Utilizza ft_printf
    size_tot_ft = ft_printf("Integer: %d\n", i);
    size_tot_ft += ft_printf("Uns int: %u\n", u);
    size_tot_ft += ft_printf("String: %s\n", s);
    size_tot_ft += ft_printf("HexL: %x\n", x);
    size_tot_ft += ft_printf("HexU: %X\n", x);
    size_tot_ft += ft_printf("Character: %c\n", c);
    size_tot_ft += ft_printf("Pointer: %p\n", p);
    printf("ft_printf ha restituito %d caratteri stampati.\n", size_tot_ft);

    // Utilizza printf originale
    printf("Original printf:\n");
    size_tot = printf("Integer: %d\n", i);
    size_tot += printf("Uns int: %u\n", u);
    size_tot += printf("String: %s\n", s);
    size_tot += printf("HexL: %x\n", x);
    size_tot += printf("HexU: %X\n", x);
    size_tot += printf("Character: %c\n", c);
    size_tot += printf("Pointer: %p\n", p);
    printf("printf ha restituito %d caratteri stampati.\n", size_tot);
}*/
/*  // Utilizza ft_printf
    ft_printf("Integer: %d\n", i);
    ft_printf("String: %s\n", s);
    ft_printf("hexL: %x\n", x);
    ft_printf("Character: %c\n", c);
    ft_printf("Pointer: %p\n", p);
    
    // Utilizza printf originale
    printf("Original printf:\n");
    printf("Integer: %d\n", i);
    printf("String: %s\n", s);
    printf("hexL: %x\n", x);
    printf("Character: %c\n", c);
    printf("Pointer: %p\n", p);

    return 0;
}*/
