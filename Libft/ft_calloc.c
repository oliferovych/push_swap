/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:39:01 by dolifero          #+#    #+#             */
/*   Updated: 2024/03/08 16:51:37 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*result;

	result = malloc(count * size);
	i = 0;
	if (!result)
		return (NULL);
	while (i < count * size)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}

// #include <stdio.h>
// int main() {
//     // Test parameters
//     size_t count = 5;
//     size_t size = sizeof(int);

//     // Allocate memory using ft_calloc
//     int *arr = (int *)ft_calloc(count, size);

//     // Check if allocation was successful
//     if (arr == NULL) {
//         printf("Memory allocation failed.\n");
//         return (1);
//     }

//     // Print the allocated memory
//     printf("Allocated memory using ft_calloc:\n");
//     for (size_t i = 0; i < count; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     // Free the allocated memory
//     free(arr);

//     return (0);
// }
