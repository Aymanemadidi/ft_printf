/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces_zeros_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airball <airball@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 00:48:02 by ael-madi          #+#    #+#             */
/*   Updated: 2020/11/12 18:49:54 by airball          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	spaces_zeros_hexa(long int i, t_format *format,
		int *fill_spaces, int *fill_zero)
{
	if ((format->prec == 0 && format->prec_check && i == 0)
		|| (format->prec_check && format->prec > 0)
			|| (format->width < len_nb_hexa(i, format) && format->prec < 0))
		format->minus_flag = 0;
	if (format->width < 0)
		format->zero_flag = 1;
	if (format->minus_flag && format->width > 0)
		*fill_zero = ft_abs(format->width) - len_nb_hexa(i, format);
	else if (format->prec > len_nb_hexa(i, format)
		|| (format->minus_flag && format->prec_check && format->w_check))
	{
		*fill_zero = ft_abs(format->prec) - len_nb_hexa(i, format) +
			(i < 0 && format->prec > 0);
	}
	//printf("len_nb_hexa: %d\nfill_zero: %d\n", len_nb_hexa(i, format), *fill_zero);
	if (ft_abs(format->width) > len_nb_hexa(i, format) + *fill_zero)
	{
		*fill_spaces = ft_abs(format->width) - len_nb_hexa(i, format)
			- (*fill_zero < 0 ? 0 : *fill_zero);
	}
	//printf("fill_spaces: %d\n", *fill_spaces);
	if (format->invalid)
		*fill_spaces -= 8;
	if (format->prec == 0 && format->prec_check && i == 0 && format->w_check
			&& format->width != 0)
		norme(format, fill_spaces);
}

void	norme(t_format *format, int *fill_spaces)
{
	format->minus_flag = 0;
	if (format->p_special == 1 && format->prec_check && format->prec == 0 &&
	format->width > 0 && format->width < 3)
		(*fill_spaces)--;
	(*fill_spaces)++;
}
