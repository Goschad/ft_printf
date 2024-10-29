/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:51:37 by mbouaza           #+#    #+#             */
/*   Updated: 2023/01/19 03:07:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// for %s //

int	ft_putstr(const char *str, int *error)
{
	int	len;

	len = 0;
	if (str == NULL)
	{
		ft_putstr("(null)", error);
		return (6);
	}
	else
	{
		while (str[len] != '\0')
			ft_putchar(str[len++], error);
	}
	return (len);
}
