/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airball <airball@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:06:30 by ael-madi          #+#    #+#             */
/*   Updated: 2020/11/12 18:23:21 by airball          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_hexa(long int i, t_format *format, int *count, char *str)
{
	int fill_spaces;
	int fill_zero;

	fill_spaces = 0;
	fill_zero = 0;
	if (i < 0)
		i += 4294967296;	
	if (format->prec_check && format->prec == 0 && format->minus_flag)
		format->minus_flag = 0;
	spaces_zeros_hexa(i, format, &fill_spaces, &fill_zero);
	if (!(format->zero_flag) && !(format->minus_flag))
		ft_putnchar(' ', fill_spaces, count);
	if (!(format->zero_flag) && format->minus_flag)
		ft_putnchar('0', fill_spaces, count);
	ft_putnchar('0', fill_zero, count);
	if (format->p_special)
		ft_putnstr((str[10] == 'A' ? "0X" : "0x"), 2, count);
	if (format->spec == 'p' && format->invalid)
		ft_putnchar('f', 8, count);		
	if (format->prec != 0 || i != 0 || !(format->prec_check))
		ft_putnbr_hexa(i, count, str);	
	if (format->zero_flag)
		ft_putnchar(' ', fill_spaces, count);
}
