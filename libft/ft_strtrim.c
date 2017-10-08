/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:28:12 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/09 17:28:15 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	size_t	slen;
	size_t	i;

	ret = NULL;
	if (s)
	{
		slen = ft_strlen(s);
		if ((ret = (char*)ft_memalloc(slen + 1)) == NULL)
			return (NULL);
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		if (ft_strlen(s) == 0)
			return (ret = ft_strnew(0));
		i = 0;
		while (s[i])
			i++;
		i--;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
		ft_strncpy(ret, s, i + 1);
		return (ret);
	}
	return (NULL);
}
