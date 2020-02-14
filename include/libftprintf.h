/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:33:38 by eduwer            #+#    #+#             */
/*   Updated: 2020/02/14 11:53:49 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>
# include <stddef.h>
# include <locale.h>
# include <math.h>
# include "./libft.h"

# include <stdio.h>

# define MIN_BUFFER_EXPAND_SIZE 15

# define FLAG_HASHTAG 0x1
# define FLAG_ZERO 0x2
# define FLAG_MINUS 0x4
# define FLAG_PLUS 0x8
# define FLAG_SPACE 0x10
# define FLAG_STAR 0x20
# define FLAG_DOLLAR 0x40

typedef	enum t_modifier
{
	m_undefined,
	m_hh,
	m_h,
	m_l,
	m_ll,
	m_q,
	m_L,
	m_j,
	m_z,
	m_Z,
	m_t
}		e_modifier;

typedef enum t_convertion
{
	c_undefined,
	c_int,
	c_uint,
	c_char,
	c_uoctal,
	c_uhexlowcase,
	c_uhexuppcase,
	c_scilowcase,
	c_sciuppcase,
	c_lowdouble,
	c_uppdouble,
	c_pointer,
	c_string,
	c_storewrittenchars,
}		e_convertion;

typedef enum t_state
{
	false,
	true,
	error
}			e_state;

typedef struct	s_context
{
	const char		*restrict input;
	va_list			*list;
	char			*output;
	size_t			size_allocated;
	int				in_i;
	int				out_i;
	int				field_width;
	int				precision;
	int				nb_printed;
	e_modifier		modifier;
	e_convertion	convertion;
	int				flags;
}				t_context;

int				ft_printf(const char *restrict str, ...);
void			begin_flags(char *str, va_list list, t_context *ctx);
void			init_context(t_context *ctx, const char *restrict str, \
					va_list *list);
void			reset_flags(t_context *ctx);
e_state			expand_string(t_context *ctx, size_t size);
e_state			main_loop(t_context *ctx);
e_state			append_string(t_context *ctx, const char *str);
e_state			append_string_size(t_context *ctx, const char *str, int n);
size_t			to_next_percent(t_context *ctx);
e_state			begin_percent_process(t_context *ctx);
e_state			get_flags(t_context *ctx);
e_state			get_modifiers(t_context *ctx);
e_state			get_convertion(t_context *ctx);
e_state			make_ze_convertion(t_context *ctx);
e_state			get_field_width(t_context *ctx);
e_state			get_precision(t_context *ctx);
e_state			convert_string(t_context *ctx);
e_state			convert_char(t_context *ctx);
e_state			convert_int(t_context *ctx);
e_state			convert_uint(t_context *ctx);
e_state			convert_octal_hexa(t_context *ctx);
e_state			convert_double(t_context *ctx);
char			*space_and_plus_flag(t_context *ctx, char *str);
char			*precision_and_zero_padding(char *str, int nb_to_add);
char			*field_width(t_context *ctx, char *str);
char			*fill_to_precision_int(t_context *ctx, char *str);
e_state			convert_uint_print(t_context *ctx, char *str);
long double		ldouble_power(long double nbr, unsigned int power);
unsigned int	get_ldouble_magnitude(long double nbr);
unsigned int	get_ldouble_last_digit(long double *nbr);

#endif
