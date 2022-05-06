/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 02:10:34 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/14 02:10:37 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strl(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strd(char	*src)
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

char	*ft_sub(char const *s, int start, int len)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	if (start < ft_strl(s))
	{
		if (ft_strl(s) < len)
			len = ft_strl(s);
		ptr = (char *)malloc(len + 1);
		if (!ptr)
			return (NULL);
		while (i < len)
			ptr[i++] = s[start++];
	}
	else
		ptr = malloc(1);
	if (!ptr)
		return (ptr);
	*(ptr + i) = 0;
	return (ptr);
}

char	*ft_strj(char *s1, char *s2)
{
	char	*tp;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (!s1)
		s1 = ft_strd("");
	tp = (char *)malloc(ft_strl(s1) + ft_strl(s2) + 1);
	if (!tp)
		return (NULL);
	while (s1[i])
	{
		tp[i] = s1[i];
		i++;
	}
	while (s2[x])
		tp[i++] = s2[x++];
	free(s1);
	tp[i] = '\0';
	return (tp);
}

int	line_in_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
