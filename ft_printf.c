/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwen <marwen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:29:42 by mbouaza           #+#    #+#             */
/*   Updated: 2024/10/29 22:06:54 by marwen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_error(va_list args, int *count)
{
	write(1, "(null)", 6);
	va_end(args);
	return (*count + 6);
}

static int	format_search(va_list args, const char *format, int *i, int *error)
{
	int	len;

	len = 0;
	if (format[*i] == '%')
		len += ft_putchar(format[*i], error);
	else if (format[*i] == 'c')
		len += ft_putchar(va_arg(args, int), error);
	else if (format[*i] == 's')
		len += ft_putstr(va_arg(args, char *), error);
	else if (format[*i] == 'u')
		len += ft_putnbr_unsigned(va_arg(args, unsigned int), error);
	else if (format[*i] == 'x')
		len += ft_putnbr_hex_min(va_arg(args, unsigned int), error);
	else if (format[*i] == 'X')
		len += ft_putnbr_hex_maj(va_arg(args, unsigned int), error);
	else if (format[*i] == 'p')
		len += ft_put_ptr(va_arg(args, unsigned long long), error);
	else if (format[*i] == 'd' || format[*i] == 'i')
		len += ft_putnbr(va_arg(args, int), error);
	*i += 1;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		error;
	int		count;
	va_list	args;

	i = 0;
	error = 0;
	count = 0;
	va_start(args, format);
	if (format == NULL)
		return (check_error(args, &count));
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += format_search(args, format, &i, &error);
		}
		else
			count += ft_putchar(format[i++], &error);
	}
	if (error == -1)
		return (-1);
	va_end(args);
	return (count);
}
