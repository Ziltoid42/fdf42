/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:17:34 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/09 17:17:37 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*dst;
	char	*src;

	dst = s1;
	src = (char*)s2;
	if (dst && src)
	{
		while (*dst)
			++dst;
		while (*src)
			*dst++ = *src++;
		*dst = 0;
	}
	return (s1);
}
