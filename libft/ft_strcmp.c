/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:18:21 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/09 17:38:20 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*ts1;
	unsigned char	*ts2;

	i = 0;
	ts1 = (unsigned char*)s1;
	ts2 = (unsigned char*)s2;
	if (ts1 && ts2)
	{
		while (ts1[i] && ts2[i])
		{
			if (ts1[i] != ts2[i])
				return (ts1[i] - ts2[i]);
			i++;
		}
	}
	return (ts1[i] - ts2[i]);
}
