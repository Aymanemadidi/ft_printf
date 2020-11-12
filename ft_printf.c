/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-madi <ael-madi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 00:44:22 by ael-madi          #+#    #+#             */
/*   Updated: 2020/11/12 14:00:34 by ael-madi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		pass(va_list args, t_format *format, int *count)
{
	if (format->spec == 'c')
		handle_char((char)va_arg(args, int), format, count);
	else if (format->spec == 's')
		handle_string(va_arg(args, char*), format, count);
	else if (format->spec == '%')
	{
		if (format->prec == 0 && format->prec_check == 1 && format->width == 0
			&& format->w_check == 1)
			format->prec = 1;
		else if (format->prec == 0 && format->prec_check == 1)
			format->prec = 1;
		handle_string("%", format, count);
	}
	else if (format->spec == 'c')
		handle_char('%', format, count);
	else if (format->spec == 'd' || format->spec == 'i')
		handle_int(va_arg(args, int), format, count);
	else if (format->spec == 'u')
		handle_unsigned_int(va_arg(args, int), format, count);
	else if (format->spec == 'x')
		handle_hexa(va_arg(args, int), format, count, "0123456789abcdef");
	else if (format->spec == 'X')
		handle_hexa(va_arg(args, int), format, count, "0123456789ABCDEF");
	else if (format->spec == 'p')
		handle_pointer(va_arg(args, long int), format, count);
}

void		handle_format(char **ptr, va_list args, int *count)
{
	t_format format;

	format.w_check = 0;
	format.prec_check = 0;
	format.prec = 0;
	format.width = 0;
	find_flags(ptr, &format);
	find_width(ptr, &format, args);
	find_prec(ptr, &format, args);
	format.spec = **ptr;
	if (**ptr != '\0')
		(*ptr)++;
	pass(args, &format, count);
}

int			ft_printf(const char *format, ...)
{
	int		count;
	char	*ptr;
	va_list args;

	count = 0;
	ptr = (char *)format;
	va_start(args, format);
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			handle_format(&ptr, args, &count);
		}
		else
			ft_putnchar(*(ptr++), 1, &count);
	}
	va_end(args);
	return (count);
}
