/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanka-w <asanka-w@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:17:59 by asanka-w          #+#    #+#             */
/*   Updated: 2024/08/06 11:18:20 by asanka-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str);

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= 'A')
				&& (str[i] <= 'Z')))
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
/*
int	main(void)
{
	char	word[] = "@";
	char	*word_pointer;
	int		val;

	word_pointer = word;
	val = ft_str_is_alpha(word_pointer);
	printf("%d", val);
}*/
