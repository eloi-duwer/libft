/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 14:10:08 by eduwer            #+#    #+#             */
/*   Updated: 2021/01/08 04:50:28 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>


static inline uint64_t	get_hex(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (c - 'a' + 10);
}



static uint64_t			do_conv(char *str, size_t str_len)
{
	uint64_t	i;
	uint64_t	ret;

	i = 0;
	ret = 0;
	while (i < str_len && i < 16)
	{
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && \
			str[i] <= 'F') || (str[i] >= 'a' && str[i] <= 'f')))
		{
			write(2, "Hex string is invalid\n", 22);
			exit(1);
		}
		ret = (ret << 4) | get_hex(str[i]);
		i++;
	}
	return (ret);
}

/*
** Converts chars from str (max 16, as 1 char = 4 bits),
** assuming hex representation (no 0x at the beginning)
** pad the end with 0 if the string is too short
** ignore excess if the string is too long
*/

uint64_t		ft_char_to_hex_u64(char *str)
{
	const size_t len = ft_strlen(str);

	if (len < 16)
		write(2, "hex string is too short, padding with zeroes\n", 45);
	else if (len > 16)
		write(2, "hex string is too long, ignoring excess\n", 40);
	return (do_conv(str, len));
}
