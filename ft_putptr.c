/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralukasi <ralukasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:23:58 by ralukasi          #+#    #+#             */
/*   Updated: 2023/01/13 21:06:03 by ralukasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_one(unsigned long long nb)
{
	int				ret;

	ret = 0;
	if (nb >= 16)
	{
		ret = ret + ft_puthexa_one(nb / 16);
		ret = ret + ft_puthexa_one(nb % 16);
	}
	else
	{
		ret = ret + ft_putchar("0123456789abcdef"[nb % 16]);
		if (ret < 0)
			return (ret);
	}
	return (ret);
}

int	ft_putptr(void *format)
{
	if (!format || format == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	return (ft_puthexa_one((unsigned long long)format) + 2);
}
