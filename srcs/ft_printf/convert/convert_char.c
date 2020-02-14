/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:31:44 by eduwer            #+#    #+#             */
/*   Updated: 2017/05/22 19:20:42 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

e_state		convert_char(t_context *ctx)
{
	unsigned char c;
	unsigned char *str;
	e_state ret;

	c = (unsigned char)va_arg(*(ctx->list), int);
	if ((str = (unsigned char *)ft_memalloc(sizeof(char) * 2)) == NULL)
		return error;
	str[0] = c;
	if ((str = (unsigned char *)field_width(ctx, (char *)str)) == NULL)
		return error;
	ret = append_string(ctx, (char *)str);
	free(str);
	return ret;
}