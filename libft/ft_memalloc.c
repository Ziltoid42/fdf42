/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:11:36 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/09 17:11:39 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ret;

	ret = NULL;
	if (size)
	{
		if ((ret = (void*)malloc(size)) == NULL)
			return (NULL);
		ft_bzero(ret, size);
	}
	return (ret);
}
