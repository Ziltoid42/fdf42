/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:08:17 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/09 17:44:26 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numbercount(int n)
{
	unsigned int	tn;
	size_t			num;

	num = 0;
	if (n < 0)
	{
		num++;
		tn = -n;
	}
	else
		tn = n;
	while (tn)
	{
		num++;
		tn = tn / 10;
	}
	return (num);
}

static char		*ft_norme(int n, size_t i, char *ret)
{
	unsigned int	nl;

	nl = n;
	while (nl)
	{
		ret[i] = (nl % 10) + '0';
		nl = nl / 10;
		i--;
	}
	return (ret);
}

char			*ft_itoa(int n)
{
	char			*ret;
	size_t			num;
	size_t			i;

	num = ft_numbercount(n);
	if ((ret = (char*)ft_memalloc(sizeof(char) * (num + 1))) == NULL)
		return (NULL);
	i = 0;
	if (!n)
		ret[0] = '0';
	if (n < 0)
	{
		ret[0] = '-';
		i = num - 1;
		n = -n;
	}
	else
		i = num - 1;
	ret = ft_norme(n, i, ret);
	ret[num + 1] = 0;
	return (ret);
}
