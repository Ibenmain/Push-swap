/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 02:11:37 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 21:39:58 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_a_onplace(t_swap **a, int len, t_oper **oper)
{
	t_v	var;

	var.x = (*a)->content;
	if (len >= 2)
		var.y = (*a)->next->content;
	else
		var.y = 0;
	if (len == 3)
		var.z = (*a)->next->next->content;
	if (var.x > var.y && var.y > var.z)
	{
		add_oper(oper, swap(*a, 'a'));
		add_oper(oper, rev_rotate(a, 'a'));
	}
	else if (var.x > var.z && var.z > var.y)
		add_oper(oper, rotate(a, 'a'));
	else if (var.z > var.x && var.x > var.y)
		add_oper(oper, swap(*a, 'a'));
	else if (var.y > var.z && var.z > var.x)
	{
		add_oper(oper, rev_rotate(a, 'a'));
		add_oper(oper, swap(*a, 'a'));
	}
	else if (var.y > var.x && var.x > var.z)
		add_oper(oper, rev_rotate(a, 'a'));
}

int	ft_sort_a(t_swap **a, int len, t_oper **oper)
{
	int		x;
	int		y;
	int		z;

	x = (*a)->content;
	if (len >= 2)
		y = (*a)->next->content;
	else
		y = 0;
	if (len == 3)
		z = (*a)->next->next->content;
	else
		z = 0;
	if (len == 1)
		return (0);
	else if (len == 2 && x > y)
		add_oper(oper, swap(*a, 'a'));
	else if (ft_lstsize(*a) == 3 && len == 3)
		ft_sort_a_onplace(a, len, oper);
	else if (len == 3)
		ft_sort_asc(a, len, oper);
	return (0);
}

void	ft_sort_b_onplace(t_swap **b, int len, t_oper **oper)
{
	t_v	var;

	var.x = (*b)->content;
	if (len >= 2)
		var.y = (*b)->next->content;
	else
		var.y = 0;
	if (len == 3)
		var.z = (*b)->next->next->content;
	if (var.x < var.y && var.y < var.z)
	{
		add_oper(oper, swap(*b, 'b'));
		add_oper(oper, rev_rotate(b, 'b'));
	}
	else if (var.x < var.z && var.z < var.y)
		add_oper(oper, rotate(b, 'b'));
	else if (var.z < var.x && var.x < var.y)
		add_oper(oper, swap(*b, 'b'));
	else if (var.y < var.z && var.z < var.x)
	{
		add_oper(oper, rev_rotate(b, 'b'));
		add_oper(oper, swap(*b, 'b'));
	}
	else if (var.y < var.x && var.x < var.z)
		add_oper(oper, rev_rotate(b, 'b'));
}

int	ft_sort_b(t_swap **b, int len, t_oper **oper)
{
	int		x;
	int		y;
	int		z;

	x = (*b)->content;
	if (len >= 2)
		y = (*b)->next->content;
	else
		y = 0;
	if (len == 3)
		z = (*b)->next->next->content;
	else
		z = 0;
	if (len == 1)
		return (0);
	else if (len == 2 && x < y)
		add_oper(oper, swap(*b, 'b'));
	else if (ft_lstsize(*b) == 3 && len == 3)
		ft_sort_b_onplace(b, len, oper);
	else if (len == 3)
		ft_sort_desc(b, len, oper);
	return (0);
}
