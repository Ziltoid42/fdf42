/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:02:02 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/09 17:02:09 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrcpy(char **arr)
{
	char	**new_arr;
	t_uint	pos;

	if (!(new_arr = (char**)malloc(sizeof(char*) * (ft_arrlen(arr) + 1))))
		return (NULL);
	pos = 0;
	while (arr && arr[pos])
	{
		new_arr[pos] = ft_strdup(arr[pos]);
		pos++;
	}
	new_arr[pos] = NULL;
	return (new_arr);
}
