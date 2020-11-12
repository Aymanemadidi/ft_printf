/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-madi <ael-madi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 00:46:26 by ael-madi          #+#    #+#             */
/*   Updated: 2020/11/09 10:44:06 by ael-madi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_char(char c, t_format *format, int *count)
{
	int fill_spaces;

	fill_spaces = ft_abs(format->width) - 1;
	if (format->width < 0)
		format->zero_flag = 1;
	ft_putnchar(' ', fill_spaces * (1 - format->zero_flag), count);
	ft_putnchar(c, 1, count);
	ft_putnchar(' ', fill_spaces * format->zero_flag, count);
}
