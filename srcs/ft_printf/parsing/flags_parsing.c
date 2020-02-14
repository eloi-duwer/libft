/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:31:44 by eduwer            #+#    #+#             */
/*   Updated: 2017/05/22 19:20:42 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static e_state get_all_flags(t_context *ctx, int prev_i);

e_state get_flags(t_context *ctx)
{
	if (ctx->input[ctx->in_i] == '%')
	{
		ctx->in_i++;
		return append_string_size(ctx, "%", 1);
	}
	return get_all_flags(ctx, -1);
}

static e_state get_all_flags(t_context *ctx, int prev_i)
{
	while (prev_i == -1 || prev_i != ctx->in_i)
	{
		prev_i = ctx->in_i;
		if (ctx->input[ctx->in_i] == '#')
			ctx->flags |= FLAG_HASHTAG;
		else if (ctx->input[ctx->in_i] == '0')
			ctx->flags |= FLAG_ZERO;
		else if (ctx->input[ctx->in_i] == '-')
			ctx->flags |= FLAG_MINUS;
		else if (ctx->input[ctx->in_i] == '+')
			ctx->flags |= FLAG_PLUS;
		else if (ctx->input[ctx->in_i] == ' ')
			ctx->flags |= FLAG_SPACE;
		else if (ctx->input[ctx->in_i] == '*')
			ctx->flags |= FLAG_STAR;
		else if (ctx->input[ctx->in_i] == '$')
			ctx->flags |= FLAG_DOLLAR;
		else
			ctx->in_i--;
		ctx->in_i++;
	}
	return get_field_width(ctx);
}