/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 04:56:14 by obadran           #+#    #+#             */
/*   Updated: 2024/06/27 05:01:10 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char const	*ini;

	ini = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ini = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((char *)ini);
}
