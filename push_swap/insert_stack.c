/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:19:48 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 23:19:56 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap	*ft_lstnew(int content)
{
	t_swap	*new;

	new = (t_swap *)malloc(sizeof(t_swap));
	if (!new)
		return (NULL);
	else
	{
		new->content = content;
		new->next = NULL;
	}
	return (new);
}

void	ft_lstadd_back(t_swap **alst, t_swap *new)
{
	t_swap	*ptr;

	if (alst)
	{
		if (*alst == NULL)
		{
			*alst = new;
		}
		else
		{
			ptr = *alst;
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = new;
		}
	}
}

void	ft_lstadd_front(t_swap **alst, t_swap *new)
{
	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			new->next = *alst;
			*alst = new;
		}
	}
}

t_swap	*ft_add_element(int agc, int *content)
{
	t_swap	*list;
	int		i;

	list = NULL;
	i = -1;
	while (++i < agc)
	{
		ft_lstadd_back(&list, ft_lstnew(content[i]));
	}
	return (list);
}
