/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:26:42 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/09 17:26:46 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*buf;

	buf = (char*)s;
	if (buf)
	{
		while (*buf)
			buf++;
		if ((char)c == 0)
			return (buf);
		while (buf >= s)
		{
			if (*buf == (char)c)
				return (buf);
			buf--;
		}
	}
	return (NULL);
}
