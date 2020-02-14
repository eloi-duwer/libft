/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:31:44 by eduwer            #+#    #+#             */
/*   Updated: 2017/05/22 19:20:42 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int		ft_printf(const char *restrict str, ...)
{
	va_list	list;
	t_context ctx;

	va_start(list, str);
	init_context(&ctx, str, &list);
	reset_flags(&ctx);
	if (main_loop(&ctx) == error)
		return -1;
	va_end(list);
	ft_putstr(ctx.output);
	free(&(ctx.output[0]));
	return (ctx.out_i);
}

e_state	main_loop(t_context *ctx)
{
	size_t next_percent;

	while (ctx->input[ctx->in_i] != '\0')
	{
		next_percent = to_next_percent(ctx);
		if (next_percent > 0 && append_string_size(ctx, \
			&(ctx->input[ctx->in_i]), next_percent) == error)
			return error;
		else if (next_percent == 0 && begin_percent_process(ctx) == error)
				return error;
		ctx->in_i += next_percent;
	}
	return true;
}

size_t	to_next_percent(t_context *ctx)
{
	size_t i;

	i = 0;
	while (ctx->input[ctx->in_i + i] != '\0' && \
		ctx->input[ctx->in_i + i] != '%')
		++i;
	return (i);
}