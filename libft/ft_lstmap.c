/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:10:48 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/09 17:10:52 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list	*ret;
	t_list	*prev;
	t_list	*telem;

	ret = NULL;
	if (lst && f)
	{
		ret = f(lst);
		prev = ret;
		lst = lst->next;
		while (lst)
		{
			if ((telem = f(lst)) == NULL)
				return (NULL);
			prev->next = telem;
			prev = telem;
			lst = lst->next;
		}
		prev->next = NULL;
	}
	return (ret);
}
