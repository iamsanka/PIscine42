/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanka-w <asanka-w@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:28:59 by asanka-w          #+#    #+#             */
/*   Updated: 2024/08/15 15:29:03 by asanka-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_len(int size, char *result, char *sep, char **strs)
{
	char	*current_pos;
	int		i;

	i = 0;
	if (result == NULL)
	{
		return (NULL);
	}
	current_pos = result;
	i = 0;
	while (i < size)
	{
		ft_strcpy(current_pos, strs[i]);
		current_pos += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(current_pos, sep);
			current_pos += ft_strlen(sep);
		}
		i++;
	}
	*current_pos = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total_len;
	char	*result;

	i = 0;
	total_len = 0;
	if (size == 0)
	{
		result = (char *)malloc(1);
		if (result != NULL)
			result[0] = '\0';
		return (result);
	}
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	total_len += ft_strlen(sep) * (size - 1);
	result = (char *)malloc((total_len + 1) * sizeof(char));
	get_len(size, result, sep, strs);
	return (result);
}
/*
int	main(void)
{
	int		size;
	char	*strs[] = {"Hello", "World", "!"};
	char	*sep;
	char	*result;

	size = 3;
	sep = " ";
	result = ft_strjoin(size, strs, sep);
	if (result != NULL)
	{
		printf("%s\n", result);
		free(result);
	}
	else
	{
		printf("Failed to allocate memory\n");
	}
	return (0);
}*/
