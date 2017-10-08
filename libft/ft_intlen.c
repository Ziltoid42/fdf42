/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:05:27 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/09 17:05:33 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int number)
{
	int lenght;

	lenght = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		lenght++;
	while (number != 0)
	{
		lenght++;
		number = number / 10;
	}
	return (lenght);
}
