/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:17:11 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/09 17:17:13 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_quicksort(int *base, int start, int end)
{
	int		left;
	int		right;
	int		pivot;

	left = start - 1;
	right = end + 1;
	pivot = base[start];
	if (start >= end)
		return (base);
	while (left < right)
	{
		right--;
		while (base[right] > pivot)
			right--;
		left++;
		while (base[left] < pivot)
			left++;
		if (left < right)
			ft_swapint(&base[left], &base[right]);
	}
	base = ft_quicksort(base, start, right);
	base = ft_quicksort(base, right + 1, end);
	return (base);
}
