/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralukasi <ralukasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:38:05 by ralukasi          #+#    #+#             */
/*   Updated: 2023/01/13 21:04:23 by ralukasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
char	*ft_strchr(const char *str, int c);
int		ft_leng(long number);
int		ft_putnbr(int n);
int		ft_puthexa(int nb, char format);
int		ft_putptr(void *format);
int		ft_putnbr_u(unsigned int n);

#endif
