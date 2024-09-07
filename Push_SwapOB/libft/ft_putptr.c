/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:48:46 by obadran           #+#    #+#             */
/*   Updated: 2024/07/28 11:52:42 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	rec_print(unsigned long n, const char *base)
{
	int	len;

	len = 0;
	if (n > (ft_strlen(base) - 1))
		len += rec_print(n / ft_strlen(base), base);
	len += ft_putchar(*(base + (n % ft_strlen(base))));
	return (len);
}

int	ft_putptr(unsigned long long *ptr)
{
	unsigned long	n;
	const char		*base;
	int				len;

	len = 0;
	n = (unsigned long)ptr;
	base = "0123456789abcdef";
	if (ptr == NULL)
	{
		ft_putstr("(nil)");
		len += 5;
		return (len);
	}
	len = ft_putstr("0x");
	len += rec_print(n, base);
	return (len);
}
