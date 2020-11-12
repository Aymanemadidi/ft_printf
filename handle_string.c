/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-madi <ael-madi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 00:47:29 by ael-madi          #+#    #+#             */
/*   Updated: 2020/11/09 10:46:33 by ael-madi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_string(char *str, t_format *format, int *count)
{
	int fill_spaces;
	int print_len;

	if (format->width < 0)
		format->zero_flag = 1;
	if (str == NULL)
	{
		handle_string("(null)", format, count);
		return ;
	}
	if (ft_abs(format->prec) < ft_strlen(str) && format->prec_check == 1 &&
		format->prec >= 0)
		print_len = ft_abs(format->prec);
	else
		print_len = ft_strlen(str);
	fill_spaces = ft_abs(format->width) - print_len;
	ft_putnchar((format->minus_flag ? '0' : ' '), fill_spaces *
		(1 - format->zero_flag), count);
	ft_putnstr(str, print_len, count);
	ft_putnchar(' ', fill_spaces * format->zero_flag, count);
}
