/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 14:10:08 by eduwer            #+#    #+#             */
/*   Updated: 2021/01/02 01:24:49 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdbool.h>
#include <stdlib.h>

static int	get_hex(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (c - 'A' + 10);
}

static bool	is_hex(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'));
}

static bool	conv_hex(uint8_t *pt_base, uint8_t *pt, int state, char c)
{
	if (!is_hex(c))
	{
		free(pt_base);
		return (false);
	}
	*pt |= get_hex(c) << (state * 4);
	return (true);
}

uint8_t		*ft_char_to_hex(char *str, size_t *out_size)
{
	uint8_t			*pt[2];
	size_t			len;
	int				state;

	len = ft_strlen(str);
	*out_size = len / 2 + len % 2;
	if ((pt[0] = (uint8_t *)ft_memalloc(*out_size)) == NULL)
		return (NULL);
	ft_strtoupper(str);
	pt[1] = pt[0] + (*out_size) - 1;
	state = 0;
	while (len > 0)
	{
		if (conv_hex(pt[0], pt[1], state, str[len - 1]) == false)
			return (NULL);
		if (state == 1)
			pt[1]--;
		state = !state;
		len--;
	}
	return (pt[0]);
}
