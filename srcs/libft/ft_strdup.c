/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 21:40:32 by eduwer            #+#    #+#             */
/*   Updated: 2021/05/14 18:07:19 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <libft.h>

char		*ft_strdup(char *src)
{
	size_t	src_len;
	char	*newstr;

	src_len = ft_strlen(src);
	newstr = malloc(sizeof(char) * (src_len + 1));
	if (newstr == NULL)
		return (newstr);
	ft_memcpy(newstr, src, src_len);
	newstr[src_len] = '\0';
	return (newstr);
}
