/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:20:32 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 21:43:19 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	while ((*s1 - *s2) == 0 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	if ((*s1 - *s2) != 0)
		return (0);
	return (1);
}

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

int	list_sorted(t_swap **a)
{
	int		i;
	t_swap	*head;

	head = *a;
	i = ft_lstsize(head);
	while (head && head->next && i >= 2)
	{
		if (head->content >= head->next->content)
			return (0);
		else
			head = head->next;
	}
	return (1);
}
