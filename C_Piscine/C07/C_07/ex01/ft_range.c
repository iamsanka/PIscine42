/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanka-w <asanka-w@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:06:47 by asanka-w          #+#    #+#             */
/*   Updated: 2024/08/14 18:06:48 by asanka-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	size;
	int	i;

	if (min >= max)
	{
		return (NULL);
	}
	else
	{
		size = max - min;
		range = (int *)malloc(size * sizeof(int));
		if (range == NULL)
		{
			return (NULL);
		}
		i = 0;
		while (min < max)
		{
			range[i] = min;
			min++;
			i++;
		}
		return (range);
	}
}
/*
int	main(void)
{
	int *range;
	int size;
	int i;

	size = ft_ultimate_range(&range, 5, 10);
	if (size <= 0)
	{
		printf("Failed\n");
		return (1);
	}
	for (i = 0; i < size; i++)
	{
		printf("%d ", range[i]);
	}
	printf("\n");
	free(range);
	return (0);
}*/
