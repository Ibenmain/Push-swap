/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:26:06 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 21:48:24 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_4(int t1, int t2, int t3, int t4)
{
	int	min;

	min = 0;
	if (t1 < t2 && t1 < t3 && t1 < t4)
		min = t1;
	else if (t2 < t1 && t2 < t3 && t2 < t4)
		min = t2;
	else if (t3 < t1 && t3 < t2 && t3 < t4)
		min = t3;
	else if (t4 < t1 && t4 < t2 && t4 < t3)
		min = t4;
	return (min);
}

void	sort_for(t_swap **a, t_swap	**b, t_oper **oper)
{
	int		t1;
	int		t2;
	int		t3;
	int		t4;

	t1 = (*a)->content;
	t2 = (*a)->next->content;
	t3 = (*a)->next->next->content;
	t4 = (*a)->next->next->next->content;
	if (ft_min_4(t1, t2, t3, t4) == t2)
		add_oper(oper, swap(*a, 'a'));
	else if (ft_min_4(t1, t2, t3, t4) == t3)
	{
		add_oper(oper, rotate(a, 'a'));
		add_oper(oper, rotate(a, 'a'));
	}
	else if (ft_min_4(t1, t2, t3, t4) == t4)
		add_oper(oper, rev_rotate(a, 'a'));
	add_oper(oper, push(b, a, 'b'));
	ft_sort_three(*a, oper);
	add_oper(oper, push(a, b, 'a'));
}
