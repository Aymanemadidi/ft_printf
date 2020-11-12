/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-madi <ael-madi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 00:48:19 by ael-madi          #+#    #+#             */
/*   Updated: 2020/11/09 08:41:56 by ael-madi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnstr(char *str, int n, int *count)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putnchar(*(str++), 1, count);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}
