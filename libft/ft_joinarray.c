/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinarray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:09:15 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/09 17:09:19 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinarray(char **av)
{
	char	*ret;
	int		i;

	i = 1;
	ret = av[0];
	while (av[i])
	{
		ft_strcat(ret, " ");
		ft_strcat(ret, av[i]);
		i++;
	}
	return (ret);
}
