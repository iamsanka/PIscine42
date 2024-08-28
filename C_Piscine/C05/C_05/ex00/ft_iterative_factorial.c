/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanka-w <asanka-w@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:51:06 by asanka-w          #+#    #+#             */
/*   Updated: 2024/08/12 15:51:07 by asanka-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		return (0);
	}
	else
	{
		if (nb == 0 || nb == 1)
		{
			return (1);
		}
		else
		{
			while (nb >= 1)
			{
				i = i * nb;
				nb--;
			}
			return (i);
		}
	}
}
/*
int	main(void)
{
	int	num;
	int	a;

	num = 4;
	a = ft_iterative_factorial(num);
	printf("%d \n", a);
}*/
