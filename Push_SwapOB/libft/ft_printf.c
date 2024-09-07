/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 23:58:16 by obadran           #+#    #+#             */
/*   Updated: 2024/09/06 11:59:18 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	visualize(char c, int *count, va_list *args)
{
	if (c == 'c')
		*count += ft_putchar(va_arg(*args, int));
	if (c == 's')
		*count += ft_putstr(va_arg(*args, char *));
	if (c == 'u')
		*count += ft_putunbr(va_arg(*args, unsigned int));
	if (c == 'd' || c == 'i')
		*count += ft_putnbr(va_arg(*args, int));
	if (c == 'p')
		*count += ft_putptr(va_arg(*args, unsigned long long *));
	if (c == 'x' || c == 'X')
		*count += ft_puthex(va_arg(*args, unsigned int), c);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[++i] && str[i] != '%')
			visualize(str[i], &count, &args);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
