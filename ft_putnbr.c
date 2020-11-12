/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-madi <ael-madi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 00:45:55 by ael-madi          #+#    #+#             */
/*   Updated: 2020/11/12 14:37:25 by ael-madi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(long int nb, int *count)
{
	long int a;

	a = nb;
	if (a < 0)
		a = a * (-1);
	if (a > 9)
	{
		ft_putnbr(a / 10, count);
		ft_putnchar(a % 10 + '0', 1, count);
	}
	else
		ft_putnchar(a + '0', 1, count);
}

void	ft_putnbr_hexa(long int nb, int *count, char *str)
{
	long int a;

	a = nb;
	if (a < 0)
		a = a * (-1);
	if (a > 15)
	{
		ft_putnbr_hexa(a / 16, count, str);
		ft_putnchar(*(a % 16 + str), 1, count);
	}
	else
	{
		ft_putnchar(*(a + str), 1, count);
		//printf("im here");
	}
}
