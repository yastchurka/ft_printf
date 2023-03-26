/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralukasi <ralukasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:46:57 by ralukasi          #+#    #+#             */
/*   Updated: 2023/01/10 16:57:17 by ralukasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(int nb, char format)
{
	unsigned int	u;
	int				ret;

	ret = 0;
	u = (unsigned int)nb;
	if (u >= 16)
	{
		ret = ret + ft_puthexa(u / 16, format);
		ret = ret + ft_puthexa(u % 16, format);
	}
	else
	{
		if (format == 'x')
			ret = ret + ft_putchar("0123456789abcdef"[u % 16]);
		else
			ret = ret + ft_putchar("0123456789ABCDEF"[u % 16]);
		if (ret < 0)
			return (ret);
	}
	return (ret);
}
