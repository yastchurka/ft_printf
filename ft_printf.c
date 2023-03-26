/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralukasi <ralukasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:42:30 by ralukasi          #+#    #+#             */
/*   Updated: 2023/01/13 21:05:44 by ralukasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_datatype(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthexa(va_arg(args, int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	else if (format == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (format == 'u')
		return (ft_putnbr_u(va_arg(args, int)));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			len = len + ft_datatype(format[i + 1], args);
			i++;
		}
		else
			len = len + ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

/*     int main(void)
{
	int ptr = 7;
	void *h = &ptr;
	//ft_printf(" Lets%p \n ", 2147483647);
	printf("PRINTF:%p\n", h);
	return 0;
}        */
