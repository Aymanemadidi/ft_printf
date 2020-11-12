/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces_zeros_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-madi <ael-madi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 00:48:07 by ael-madi          #+#    #+#             */
/*   Updated: 2020/11/12 08:11:41 by ael-madi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	spaces_zeros_int(long int i, t_format *format,
		int *fill_spaces, int *fill_zero)
{
	if ((format->prec == 0 && format->prec_check && i == 0)
		|| (format->prec_check && format->prec > 0)
			|| (format->width < len_nb(i) && format->prec < 0))
		format->minus_flag = 0;
	if (format->width < 0)
		format->zero_flag = 1;
	if (format->minus_flag && format->width > 0)
		*fill_zero = ft_abs(format->width) - len_nb(i);
	else if (format->prec >= len_nb(i)
		|| (format->minus_flag && format->prec_check && format->w_check))
	{
		*fill_zero = ft_abs(format->prec) - len_nb(i) +
			(i < 0 && format->prec > 0);
	}
	if (ft_abs(format->width) > len_nb(i) + *fill_zero)
	{
		*fill_spaces = ft_abs(format->width) - len_nb(i) -
			(*fill_zero < 0 ? 0 : *fill_zero);
	}
	if (format->prec == 0 && format->prec_check && i == 0 && format->w_check
			&& format->width != 0)
	{
		format->minus_flag = 0;
		(*fill_spaces)++;
	}
}
