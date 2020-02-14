/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_convertion_process.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:31:44 by eduwer            #+#    #+#             */
/*   Updated: 2017/05/22 19:20:42 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

e_state begin_percent_process(t_context *ctx)
{
	ctx->in_i++;
	reset_flags(ctx);
	return get_flags(ctx);
}

e_state make_ze_convertion(t_context *ctx)
{
	if (ctx->convertion == c_string)
		return convert_string(ctx);
	else if (ctx->convertion == c_int)
		return convert_int(ctx);
	else if (ctx->convertion == c_uint)
		return convert_uint(ctx);
	else if (ctx->convertion == c_uoctal || ctx->convertion == c_uhexlowcase \
		|| ctx->convertion == c_uhexuppcase)
		return convert_octal_hexa(ctx);
	else if (ctx->convertion == c_pointer)
	{
		ctx->flags |= FLAG_HASHTAG;
		return convert_octal_hexa(ctx);
	}
	else if (ctx->convertion == c_char)
		return convert_char(ctx);
	else if (ctx->convertion == c_lowdouble || ctx->convertion == c_uppdouble)
		return convert_double(ctx);
	return true;
}