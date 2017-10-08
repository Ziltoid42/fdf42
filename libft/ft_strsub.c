/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:27:52 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/09 17:27:54 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	slen;
	size_t	i;

	ret = NULL;
	if (s)
	{
		slen = ft_strlen(s);
		if (!slen || start > slen || len > slen)
			return (NULL);
		if ((ret = (char*)ft_memalloc(sizeof(char) * len + 1)) == NULL)
			return (NULL);
		i = 0;
		while (s[i] && i < len)
		{
			ret[i] = s[start];
			i++;
			start++;
		}
		ret[i] = 0;
		return (ret);
	}
	return (NULL);
}
