/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:39:11 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 21:43:08 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*push(t_swap **a, t_swap **b, char c)
{
	t_swap	*tmp;

	tmp = *b;
	if (!tmp)
		return ("");
	(*b) = (*b)->next;
	tmp->next = (*a);
	(*a) = tmp;
	if (c == 'a')
		return ("pa");
	return ("pb");
}

char	*swap(t_swap *head, char c)
{
	t_swap	*tmp;
	int		swp;

	tmp = head;
	if (tmp && tmp->next)
	{
		swp = tmp->content;
		tmp->content = tmp->next->content;
		tmp->next->content = swp;
		if (c == 'a')
			return ("sa");
		else if (c == 'b')
			return ("sb");
	}
	return ("");
}

char	*rotate(t_swap **head, char c)
{
	t_swap	*tmp;
	t_swap	*rot;

	tmp = *head;
	if (tmp && tmp->next)
	{
		(*head) = (*head)->next;
		tmp->next = NULL;
		rot = (*head);
		while (rot->next)
			rot = rot->next;
		rot->next = tmp;
		if (c == 'a')
			return ("ra");
		else if (c == 'b')
			return ("rb");
	}
	return ("");
}

char	*rev_rotate(t_swap **head, char c)
{
	t_swap	*seclast;
	t_swap	*last;

	seclast = NULL;
	last = *head;
	if (*head == NULL || (*head)->next == NULL)
		return ("");
	while (last->next != NULL)
	{
		seclast = last;
		last = last->next;
	}
	seclast->next = NULL;
	last->next = *head;
	*head = last;
	if (c == 'a')
		return ("rra");
	return ("rrb");
}
