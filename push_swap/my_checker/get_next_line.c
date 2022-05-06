/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 02:10:42 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/14 02:10:44 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*aff_line(char *str)
{
	char	*p;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n')
		i++;
	p = ft_sub(str, 0, i + 1);
	return (p);
}

char	*after_line(char *str)
{
	char	*p;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n')
		i++;
	p = ft_sub(str, i + 1, ft_strl(str) - i);
	free(str);
	return (p);
}

char	*to_ret(char **str)
{
	char	*line;

	line = ft_strd(*str);
	free(*str);
	*str = NULL;
	return (line);
}

char	*freeee(char *str)
{
	if (!str)
		return (NULL);
	if (!*str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	ssize_t		k;
	static char	*str;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (line_in_str(str))
	{
		line = aff_line(str);
		str = after_line(str);
		return (free(buf), line);
	}
	k = read(fd, buf, BUFFER_SIZE);
	if (k <= 0)
	{
		str = freeee(str);
		if (str == NULL)
			return (free(buf), NULL);
		return (free(buf), to_ret(&str));
	}
	buf[k] = 0;
	str = ft_strj(str, buf);
	return (free(buf), get_next_line(fd));
}
