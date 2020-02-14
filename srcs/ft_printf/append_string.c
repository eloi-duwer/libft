/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:31:44 by eduwer            #+#    #+#             */
/*   Updated: 2017/05/22 19:20:42 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

e_state	append_string(t_context *ctx, const char *str)
{
	return append_string_size(ctx, str, ft_strlen(str));
}

e_state	append_string_size(t_context *ctx, const char *str, int n)
{
	if (ctx->out_i + n >= (int)(ctx->size_allocated) &&
			(expand_string(ctx, n)) == error)
		return error;
	ft_memcpy(&(ctx->output[ctx->out_i]), str, n);
	ctx->out_i += n;
	ctx->output[ctx->out_i] = '\0';
	return true;
}