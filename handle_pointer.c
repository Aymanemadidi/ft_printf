/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airball <airball@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 00:47:22 by ael-madi          #+#    #+#             */
/*   Updated: 2020/11/12 18:26:59 by airball          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_pointer(long int i, t_format *format, int *count)
{	
	format->invalid = 0;
	format->p_special = 1;
	if ((void*)i <= (void*)-1 && i < 0)
		format->invalid = 1;
	handle_hexa(i, format, count, "0123456789abcdef");
}
