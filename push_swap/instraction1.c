/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:20:19 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 22:09:33 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_lstdelone(t_swap **lst)
{
	t_swap	*head;

	head = NULL;
	if (*lst)
	{
		head = *lst;
		*lst = (*lst)->next;
		free(head);
	}
}

void	sswap(t_swap *a, t_swap *b)
{
	swap(a, 'c');
	swap(b, 'c');
}

void	rrotate(t_swap **a, t_swap **b)
{
	rotate(a, 'c');
	rotate(b, 'c');
}

void	rrevrotate(t_swap **a, t_swap **b)
{
	rev_rotate(a, 'c');
	rev_rotate(b, 'c');
}
