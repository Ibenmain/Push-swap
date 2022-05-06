/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 02:10:54 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 21:28:06 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_ele(t_oper *head)
{
	ft_strdel(&head->data);
	free(head);
	head = NULL;
}

void	double_remove(t_oper *second, t_oper *first)
{
	remove_ele(second);
	remove_ele(first);
}

void	remove_oper(t_oper **head)
{
	if (*head)
	{
		if ((*head)->next)
			remove_oper(&(*head)->next);
		ft_strdel(&(*head)->data);
		free((*head)->next);
	}
}

void	add_oper(t_oper **head, char *data)
{
	t_oper	*current;
	t_oper	*new;

	current = *head;
	if (!ft_sequ(data, ""))
	{
		if (current)
		{
			if (current->next == NULL)
			{
				new = (t_oper *)malloc(sizeof(t_oper));
				new->data = ft_strdup(data);
				new->next = NULL;
				current->next = new;
				return ;
			}
			else
				return (add_oper(&(current)->next, data));
		}
		(*head) = (t_oper *)malloc(sizeof(t_oper));
		(*head)->data = ft_strdup(data);
		(*head)->next = NULL;
	}
}

void	print_operations(t_oper *oper)
{
	while (oper != NULL)
	{
		ft_putendl(oper->data);
		oper = oper->next;
	}
}
