/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanka-w <asanka-w@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:58:06 by asanka-w          #+#    #+#             */
/*   Updated: 2024/08/19 15:58:08 by asanka-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	i = 0;
	while (src[i])
		i++;
	copy = (char *)malloc(sizeof(char) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*array;
	int			i;

	if (ac < 0 || !(array = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac+ 1))))
		return (NULL);
	i = 0;
	while (i < ac)
	{
		array[i].size = 0;
		while (av[i][array[i].size])
			array[i].size++;
		array[i].str = av[i];
		array[i].copy = ft_strdup(av[i]);
		if (!array[i].copy)
		{
			while (--i >= 0)
				free(array[i].copy);
			free(array);
			return (NULL);
		}
		i++;
	}
	array[ac].str = 0;
	return (array);
}
