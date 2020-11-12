/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_width_prec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-madi <ael-madi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 00:45:28 by ael-madi          #+#    #+#             */
/*   Updated: 2020/11/12 12:39:05 by ael-madi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	find_flags(char **ptr, t_format *format)
{
	format->minus_flag = 0;
	format->zero_flag = 0;
	format->p_special = 0;
	while (ft_isflag(**ptr))
	{
		if (**ptr == '-')
			format->zero_flag = 1;
		else if (**ptr == '0')
			format->minus_flag = 1;
		(*ptr)++;
	}
}

void	find_width(char **ptr, t_format *format, va_list args)
{
	if (**ptr == '*')
	{
		format->width = va_arg(args, int);
		(*ptr)++;
		format->w_check = 1;
	}
	else if (ft_isdigit(**ptr))
	{
		format->width = ft_atoi(ptr);
		format->w_check = 1;
	}
}

void	find_prec(char **ptr, t_format *format, va_list args)
{
	if (**ptr == '.')
	{
		(*ptr)++;
		if (**ptr == '*')
		{
			format->prec = va_arg(args, int);
			(*ptr)++;
		}
		else
		{	
			//printf("\nim here1\n");
			format->prec = ft_atoi(ptr);
		}
			
		format->prec_check = 1;
	}
}
