/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanka-w <asanka-w@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:58:27 by asanka-w          #+#    #+#             */
/*   Updated: 2024/08/05 18:58:34 by asanka-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;
	int	un_int;

	un_int = n;
	i = 0;
	while (src[i] != '\0' && i < un_int)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < un_int)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "Hello World";
	char	dest[50];
	int		n;

	n = 6;
	ft_strncpy(dest, src, n);
	printf("%s", dest);
}*/
