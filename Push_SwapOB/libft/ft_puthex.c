/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:48:31 by obadran           #+#    #+#             */
/*   Updated: 2024/07/28 11:52:42 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned long nb, char format)
{
	char	*base;
	int		length;

	length = 0;
	base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
		length += ft_puthex(nb / 16, format);
	length += ft_putchar(*(base + (nb % 16)));
	return (length);
}
