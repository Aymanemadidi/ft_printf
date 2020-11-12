/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-madi <ael-madi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 00:47:45 by ael-madi          #+#    #+#             */
/*   Updated: 2020/11/12 14:37:38 by ael-madi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_format
{
	int		zero_flag;
	int		minus_flag;
	int		p_special;
	int		width;
	int		prec;
	char	spec;
	int		w_check;
	int		prec_check;
	int		invalid;
}				t_format;

int				ft_printf(const char *format, ...);
void			handle_format(char **ptr, va_list args, int *count);
void			find_flags(char **ptr, t_format *format);
void			find_width(char **ptr, t_format *format, va_list args);
void			find_prec(char **ptr, t_format *format, va_list args);
int				ft_isflag(char c);
int				ft_isdigit(char c);
int				ft_atoi(char **str);
void			ft_putnchar(char c, int n, int *count);
void			ft_putnstr(char *str, int n, int *count);
int				len_nb(long int n);
int				ft_abs(int n);
int				ft_strlen(char *str);
void			pass(va_list args, t_format *format, int *count);
void			ft_putnbr(long int nb, int *count);
void			ft_putnbr_hexa(long int nb, int *count, char *str);
void			handle_char(char c, t_format *format, int *count);
void			handle_string(char *str, t_format *format, int *count);
void			handle_int(long int i, t_format *format, int *count);
void			spaces_zeros_int(long int i, t_format *format, int *fill_spaces,
				int *fill_zero);
void			handle_unsigned_int(long int i, t_format *format, int *count);
void			handle_hexa(long int i, t_format *format, int *count,
				char *str);
void			spaces_zeros_hexa(long int i, t_format *format,
				int *fill_spaces, int *fill_zero);
void			norme(t_format *format, int *fill_spaces);
int				len_nb_hexa(long int i, t_format *format);
void			handle_pointer(long int i, t_format *format, int *count);
#endif
