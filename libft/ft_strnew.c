/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:25:26 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/09 17:25:29 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = NULL;
	{
		if ((str = (char*)ft_memalloc(sizeof(char) * size + 1)) == NULL)
			return (NULL);
		ft_bzero(str, size);
	}
	return (str);
}
