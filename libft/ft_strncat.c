/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:23:41 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/09 17:23:51 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*dst;
	char	*src;

	dst = s1;
	src = (char*)s2;
	if (dst && src)
	{
		while (*dst)
			++dst;
		while (*src && n--)
			*dst++ = *src++;
		*dst = 0;
	}
	return (s1);
}
