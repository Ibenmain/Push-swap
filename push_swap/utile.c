/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:21:42 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 23:27:13 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(char const *str, char d)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] != d)
		count = 1;
	else
		count = 0;
	while (str[i])
	{
		if (str[i] && str[i] == d && str[i + 1] != d && str[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

void	_free(char **tab)
{
	while (*tab)
		free(*tab);
	free(tab);
}

char	**ft_other_split(char const *s, char c, int i, int j)
{
	char	**tab;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	tab = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		if (end > 0 && s[end -1] != c)
		{
			tab[j++] = ft_substr(s, start, end - start);
			if (!tab[j - 1])
				return (_free(tab), NULL);
		}
	}
	return (tab[j] = NULL, tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = ft_other_split(s, c, i, j);
	return (tab);
}

char	*ft_strdup(char	*src)
{
	int		i;
	int		j;
	char	*dest;
	char	*p;

	i = 0;
	p = (char *)src;
	while (p[i] != 0)
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dest[j] = p[j];
		j++;
	}
	dest[j] = 0;
	return (dest);
}
