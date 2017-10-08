/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:12:01 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/09 17:12:07 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	p;

	i = 0;
	p = (unsigned char)c;
	while (i < n)
	{
		*(unsigned char*)dst = *(unsigned char*)src;
		if (p == *(unsigned char*)src)
			return (dst + 1);
		dst++;
		src++;
		i++;
	}
	return (NULL);
}
