/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanka-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:05:42 by asanka-w          #+#    #+#             */
/*   Updated: 2024/08/01 16:15:49 by asanka-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	value;

	if (n >= 0)
	{
		value = 'P';
		write(1, &value, 1);
	}
	else
	{
		value = 'N';
		write(1, &value, 1);
	}
}
/*
int main()
{
	int n=0;
	ft_is_negative(n);
}*/
