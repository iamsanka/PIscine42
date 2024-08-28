/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanka-w <asanka-w@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:43:38 by asanka-w          #+#    #+#             */
/*   Updated: 2024/08/07 11:43:39 by asanka-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	char	word1[] = "Hello";
	char	word2[] = "hello";
	int		n;
	char	*word1_pointer;
	char	*word2_pointer;

	word1_pointer = word1;
	word2_pointer = word2;
	n = 2;
	printf("%d ", ft_strncmp(word1, word2, n));
}*/
