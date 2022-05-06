/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:21:46 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 21:52:58 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	msg_error(char *s)
{
	write(2, s, ft_strlen(s));
	exit(0);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		size_s1;
	int		size_s2;
	char	*new;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	new = (char *)malloc((size_s1 + size_s2) + 1 * sizeof(char));
	if (!new)
		return (NULL);
	while (i < size_s1)
	{
		new[i] = s1[i];
		i++;
	}
	while (j < size_s2)
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char const *s, int start, int len)
{
	int		str_len;
	int		i;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		new = malloc(1);
	else
	{
		if (len > str_len)
			len = str_len;
		new = (char *)malloc((len + 1) * sizeof(char));
		if (!new)
			return (NULL);
		while (i < len)
			new[i++] = s[start++];
	}
	new[i] = '\0';
	return (new);
}

int	ft_atoi(char *str)
{
	int			i;
	int			signe;
	long int	nb;

	i = 0;
	signe = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] != '\0'))
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= '0') && (str[i] <= '9'))
		nb = nb * 10 + str[i++] - '0';
	if (((str[i] < '0') || (str[i] > '9')) && (str[i] != '\0'))
		msg_error("Error");
	if (signe * nb > 2147483647 || signe * nb < -2147483648)
		msg_error("Error");
	return (signe * nb);
}
