/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:09:53 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/09 17:09:57 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*talst;
	t_list	*tnext;

	if (alst && *alst && del)
	{
		talst = *alst;
		while (talst)
		{
			del(talst->content, talst->content_size);
			tnext = talst->next;
			free(talst);
			talst = tnext;
		}
		*alst = NULL;
	}
}
