/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanka-w <asanka-w@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:45:46 by asanka-w          #+#    #+#             */
/*   Updated: 2024/08/13 15:45:47 by asanka-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	po;

	i = 1;
	po = 1;
	if (nb < 0 || power < 0)
	{
		return (0);
	}
	else
	{
		if (nb == 0 || power == 0)
		{
			return (1);
		}
		while (i <= power)
		{
			po = po * nb;
			i++;
		}
	}
	return (po);
}
/*
int	main(void)
{
	int	nb;
	int	power;
	int	num;

	nb = 3;
	power = 0;
	num = ft_iterative_power(nb, power);
	printf("%d", num);
}*/
