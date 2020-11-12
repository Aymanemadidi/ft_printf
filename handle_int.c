/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-madi <ael-madi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 00:47:08 by ael-madi          #+#    #+#             */
/*   Updated: 2020/11/09 10:46:21 by ael-madi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_int(long int i, t_format *format, int *count)
{
	int fill_spaces;
	int fill_zero;

	fill_spaces = 0;
	fill_zero = 0;
	if (format->prec_check && format->prec == 0 && format->minus_flag)
		format->minus_flag = 0;
	spaces_zeros_int(i, format, &fill_spaces, &fill_zero);
	if (!(format->zero_flag) && !(format->minus_flag))
		ft_putnchar(' ', fill_spaces, count);
	if (i < 0)
		ft_putnchar('-', 1, count);
	if (!(format->zero_flag) && format->minus_flag)
		ft_putnchar('0', fill_spaces, count);
	ft_putnchar('0', fill_zero, count);
	if (format->prec != 0 || i != 0 || !(format->prec_check))
		ft_putnbr(i, count);
	if (format->zero_flag)
		ft_putnchar(' ', fill_spaces, count);
}
