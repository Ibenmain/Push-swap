/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:07:47 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 23:05:27 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sorted(t_swap *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	remove_stack(t_swap **head)
{
	if (*head)
	{
		if ((*head)->next)
			remove_stack(&(*head)->next);
		free((*head)->next);
	}
}

void	clear_memory(t_swap **a, t_swap **b)
{
	remove_stack(a);
	remove_stack(b);
}
