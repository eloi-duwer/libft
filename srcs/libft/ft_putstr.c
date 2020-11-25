/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:56:09 by eduwer            #+#    #+#             */
/*   Updated: 2020/11/25 16:04:35 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <libft.h>

void	ft_putstr(char const *s)
{
	size_t	len;

	if (s != NULL)
	{
		len = ft_strlen(s);
		write(1, s, len);
	}
}
