/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanka-w <asanka-w@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:12:20 by asanka-w          #+#    #+#             */
/*   Updated: 2024/08/15 13:12:22 by asanka-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	size;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	arr = (int *)malloc(size * sizeof(int));
	if (arr == NULL)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	*range = arr;
	return (size);
}
/*
int main()
{
    int *range = NULL;
    int min = 5;
    int max = 10;
    int size = ft_ultimate_range(&range, min, max);

    if (size > 0)
    {
        printf("The range from %d to %d is:\n", min, max);
        for (int i = 0; i < size; i++)
        {
            printf("%d ", range[i]);
        }
        free(range);
    }
    else if (size == 0)
    {
        printf("Min is greater than or equal to max.\n");
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}*/
