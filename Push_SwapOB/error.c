/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:34:51 by obadran           #+#    #+#             */
/*   Updated: 2024/09/02 16:41:44 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int is_valid_integer(char* str)
{
	while(*str == ' ' || *str == '\t')
	{
		*str++;
	}
	if(*str == '+' || *str == '-')
	{
			*str++;
	}
	if(*str == '\0')
		return 0;
	
	while(*str)
	{
		if(!ft_isdigit(*str))
		{
			ft_printf("Error\n");
			return 0;
		}
		str++;
	}

	return 1;
}

/* testing; 
#include <stdio.h>

int main() {
    char *test1 = "42";
    char *test2 = "   -123";
    char *test3 = "+456";
    char *test4 = "123abc";
    char *test5 = "+";
    char *test6 = "  ";

    printf("Test 1: %d\n", is_valid_integer(test1)); // Should print 1
    printf("Test 2: %d\n", is_valid_integer(test2)); // Should print 1
    printf("Test 3: %d\n", is_valid_integer(test3)); // Should print 1
    printf("Test 4: %d\n", is_valid_integer(test4)); // Should print 0
    printf("Test 5: %d\n", is_valid_integer(test5)); // Should print 0
    printf("Test 6: %d\n", is_valid_integer(test6)); // Should print 0

    return 0;
}
*/

int in_range(int num)
{
	int int_max = 2147483647;
	int int_min = -2147483648;

	return (num >= int_min && num <= int_max);
}


int is_duplicate(int *numbers, int size)
{
	int i = 0; 
	while (i < size)
	{
		int j = i + 1;

		while(j < size)
		{
			if(numbers[i] == numbers[j])
			{
				ft_printf("Error\n");
				return 1;
			}

			j++;
		}
		i++;
	}
	return 0;
}