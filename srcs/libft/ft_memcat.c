/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 18:08:46 by eduwer            #+#    #+#             */
/*   Updated: 2020/12/31 18:12:28 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcat(void *a, size_t size_a, void *b, size_t size_b)
{
	unsigned char *ret;

	if ((ret = (unsigned char *)malloc(size_a + size_b)) == NULL)
		return (NULL);
	ft_memcpy(ret, a, size_a);
	ft_memcpy(&ret[size_a], b, size_b);
	return (ret);
}
