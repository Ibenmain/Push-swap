/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:09:25 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 21:48:28 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_asc(t_swap **a, int len, t_oper **oper)
{
	while (len-- > 1)
	{
		if ((*a)->content > (*a)->next->content)
		{
			add_oper(oper, swap(*a, 'a'));
			add_oper(oper, rotate(a, 'a'));
		}
		else
			add_oper(oper, rotate(a, 'a'));
	}
	while (++len < 3)
	{
		add_oper(oper, rev_rotate(a, 'a'));
		if ((*a)->content > (*a)->content)
			add_oper(oper, swap(*a, 'a'));
	}
	if ((*a)->content > (*a)->next->content)
		add_oper(oper, swap(*a, 'a'));
	return (0);
}

int	ft_sort_desc(t_swap **b, int len, t_oper **oper)
{
	while (len-- > 1)
	{
		if ((*b)->content < (*b)->next->content)
		{
			add_oper(oper, swap(*b, 'b'));
			add_oper(oper, rotate(b, 'b'));
		}
		else
			add_oper(oper, rotate(b, 'b'));
	}
	while (++len < 3)
	{
		add_oper(oper, rev_rotate(b, 'b'));
		if ((*b)->content < (*b)->content)
			add_oper(oper, swap(*b, 'b'));
	}
	if ((*b)->content < (*b)->next->content)
		add_oper(oper, swap(*b, 'b'));
	return (0);
}
