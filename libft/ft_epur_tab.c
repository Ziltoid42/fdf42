/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:05:05 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/11 17:13:22 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_epur_tab(char *str)
{
	char	*ret;
	int		i;
	int		n;

	i = 0;
	n = 0;
	if ((ret = (char*)ft_memalloc(sizeof(char) * (ft_strlen(str) + 1))) == NULL)
		return (NULL);
	while (str[i])
	{
		while (str[i] == '\t' && str[i])
		{
			ret[n] = ' ';
			i++;
			n++;
		}
		if (str[i])
		{
			ret[n] = str[i];
			i++;
			n++;
		}
	}
	ret[n] = 0;
	return (ret);
}
