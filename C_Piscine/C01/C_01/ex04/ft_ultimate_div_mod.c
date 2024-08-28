/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanka-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:57:18 by asanka-w          #+#    #+#             */
/*   Updated: 2024/08/05 09:57:20 by asanka-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;
	int	temp1;

	temp = *a;
	temp1 = *b;
	*a = temp / temp1;
	*b = temp % temp1;
}
/*
int	main(void)
{
	int num1 = 10;
	int num2 = 3;
	int *a;
	int *b;

	a = &num1;
	b = &num2;

	ft_ultimate_div_mod(a, b);
}*/
