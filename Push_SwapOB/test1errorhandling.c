#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


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
			printf("Error\n");
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
				printf("Error\n");
				return 1;
			}

			j++;
		}
		i++;
	}
	return 0;
}





// Function prototypes
int is_valid_integer(char* str);
int in_range(int num);
int is_duplicate(int *numbers, int size);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <numbers...>\n", argv[0]);
        return 1; // Exit with an error code
    }

    // Array to store the parsed integers
    int *numbers = malloc(sizeof(int) * (argc - 1));
    if (!numbers) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Validate each argument
    for (int i = 1; i < argc; i++) {
        if (!is_valid_integer(argv[i])) {
            free(numbers);
            return 1; // Invalid integer
        }

        long long num = atoll(argv[i]);
        if (!in_range((int)num)) {
            printf("Error: %s is out of range\n", argv[i]);
            free(numbers);
            return 1;
        }

        numbers[i - 1] = (int)num; // Store valid integer
    }

    // Check for duplicates
    if (is_duplicate(numbers, argc - 1)) {
        free(numbers);
        return 1; // Duplicates found
    }

    // If everything is valid
    printf("All numbers are valid, within range, and no duplicates found!\n");

    // Clean up
    free(numbers);

    return 0; // Successful execution
}
