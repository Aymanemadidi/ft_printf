/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-madi <ael-madi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 00:47:34 by ael-madi          #+#    #+#             */
/*   Updated: 2020/11/09 08:41:31 by ael-madi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_unsigned_int(long int i, t_format *format, int *count)
{
	if (i < 0)
		handle_int(i + 4294967296, format, count);
	else
		handle_int(i, format, count);
}
