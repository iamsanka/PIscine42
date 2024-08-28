/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanka-w <asanka-w@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:14:15 by asanka-w          #+#    #+#             */
/*   Updated: 2024/08/05 17:14:17 by asanka-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

char	*ft_strcpy(char *dest, char *src)
{
	char	*original_dest;

	original_dest = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (original_dest);
}
/*
int	main(void)
{
	char	src[] = "hello world";
	char	dest[10]; // to give enough space for the string

	ft_strcpy(dest, src);
	printf("%s", dest);

	return (0);
}*/
