/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:48:11 by obadran           #+#    #+#             */
/*   Updated: 2024/07/28 11:52:42 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr(unsigned int nb)
{
	int	length;

	length = 0;
	if (nb >= 10)
		length += ft_putunbr(nb / 10);
	ft_putchar((nb % 10) + '0');
	length += 1;
	return (length);
}
