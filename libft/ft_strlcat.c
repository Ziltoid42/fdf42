/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:22:21 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/09 17:22:24 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len;
	size_t i;
	size_t j;

	if (dst && src)
	{
		len = ft_strlen(src);
		j = 0;
		i = 0;
		while (dst[i] && i < size)
			i++;
		if (size > 0)
			while (i < size - 1 && src[j])
				dst[i++] = src[j++];
		if (j > 0)
		{
			dst[i] = 0;
			return (len + i - j);
		}
		return (len + i);
	}
	return (0);
}
