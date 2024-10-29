/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:51:38 by espinell          #+#    #+#             */
/*   Updated: 2023/10/27 14:55:05 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *type, ...);
int	ft_strlen(const char *str);
int	ft_itoa(int n);
int	ft_unsitoa(unsigned int n);
int	ft_putchar(char c);
int	ft_hexa_low(unsigned int nb);
int	ft_hexa_upp(unsigned int nb);
int	ft_hexa_ptr(void *ptr);
int	ft_putstr(char *s);

#endif
