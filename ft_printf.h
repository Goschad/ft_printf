/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwen <marwen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:18:16 by mbouaza           #+#    #+#             */
/*   Updated: 2024/10/29 22:09:38 by marwen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/* --- ft_printf --- */

int	ft_printf(const char *format, ...);

/* --- int --- */

int	ft_strlen(const char *s);
int	ft_putnbr(int n, int *error);
int	ft_putchar(int n, int *error);
int	ft_putstr(const char *str, int *error);
int	ft_putnbr_hex_maj(unsigned int n, int *error);
int	ft_putnbr_hex_min(unsigned int n, int *error);
int	ft_put_ptr(unsigned long long nbr, int *error);
int	ft_putnbr_unsigned(unsigned int n, int *error);

#endif
