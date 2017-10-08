/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:14:02 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/09 17:41:16 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tb;

	tb = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		tb[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
