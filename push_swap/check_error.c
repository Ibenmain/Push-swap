/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:18:06 by ibenmain          #+#    #+#             */
/*   Updated: 2022/05/06 14:46:55 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_space(char *str)
{
	int	i;
	int	sp;

	i = 0;
	sp = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			sp = 1;
		i++;
	}
	if (sp == 0 || (str && str[0] == '\0'))
		msg_error("Error");
}

int	*ft_repet_nbr(char **spl, int count)
{
	int	i;
	int	j;
	int	*tab;

	i = -1;
	tab = (int *)malloc(sizeof(int) * (count + 1));
	if (!tab)
		return (NULL);
	while (spl[++i])
		tab[i] = ft_atoi(spl[i]);
	i = -1;
	while (++i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (tab[i] == tab[j])
				msg_error("Error");
			j++;
		}
	}
	return (tab);
}

int	*ft_check_error(char **av, t_swap *data)
{
	char	*tmp;
	char	**split;
	int		*stack;
	int		i;

	i = 1;
	tmp = "";
	while (av[i])
		ft_check_space(av[i++]);
	i = 1;
	while (av[i])
	{
		tmp = ft_strjoin(tmp, av[i++]);
		tmp = ft_strjoin(tmp, " ");
	}
	split = ft_split(tmp, ' ');
	data->count = ft_count(tmp, ' ');
	stack = ft_repet_nbr(split, data->count);
	free(split);
	return (stack);
}
