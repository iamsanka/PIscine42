/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanka-w <asanka-w@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:58:49 by asanka-w          #+#    #+#             */
/*   Updated: 2024/08/07 13:58:51 by asanka-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*d;

	d = dest;
	while (*d)
	{
		d++;
	}
	while (nb-- && *src)
	{
		*d++ = *src++;
	}
	*d = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	word1[] = "Hello";
	char	word2[] = "World";
	char	*word1_p;
	char	*word2_p;
	int		n;

	word1_p = word1;
	word2_p = word2;
	n = 4;
	printf("%s", ft_strncat(word1_p, word2_p, n));
}*/
