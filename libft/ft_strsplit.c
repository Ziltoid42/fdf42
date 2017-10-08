/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:27:06 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/09 17:35:37 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_count_word(char *s, char c)
{
	size_t	word;
	size_t	i;

	i = 0;
	word = 0;
	if (s[i] && (s[i] != c) && (s[i + 1] == 0))
		word++;
	if (s[i] && (s[i] != c) && (s[i + 1] == c))
		word++;
	if (s[i] && (s[i] != c) && (s[i + 1] != c) && (s[i + 1] != 0))
		word++;
	while (s[i])
	{
		if ((s[i] == c) && (s[i + 1] != c) && (s[i + 1] != 0))
			word++;
		i++;
	}
	return (word);
}

static int		ft_splitstr(char **tab, char *s, char c, size_t len)
{
	size_t	count;
	size_t	wordlen;
	size_t	i;

	count = 0;
	i = 0;
	while (count < len)
	{
		wordlen = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			wordlen++;
			i++;
		}
		if ((tab[count] = ft_strsub(&s[i - wordlen], 0, wordlen)) == NULL)
			return (0);
		count++;
	}
	tab[count] = NULL;
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	size_t	len;

	if (s)
	{
		len = ft_count_word((char*)s, c);
		if ((ret = (char**)ft_memalloc(sizeof(char*) * (len + 1))) == NULL)
			return (NULL);
		if (ft_splitstr(ret, (char*)s, c, len))
			return (ret);
		else
		{
			free(ret);
			ret = NULL;
		}
		return (ret);
	}
	return (NULL);
}
