/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:29:55 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 21:48:07 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	double_rotate_a(t_swap **a, t_oper **oper)
{
	add_oper(oper, rotate(a, 'a'));
	add_oper(oper, rotate(a, 'a'));
}

void	double_rev_rotate_a(t_swap **a, t_oper **oper)
{
	add_oper(oper, rev_rotate(a, 'a'));
	add_oper(oper, rev_rotate(a, 'a'));
}

void	sort_five(t_swap **a, t_swap	**b, t_oper **oper)
{
	int		t1;
	int		t2;
	int		t3;
	int		t4;

	t1 = (*a)->next->content;
	t2 = (*a)->next->next->content;
	t3 = (*a)->next->next->next->content;
	t4 = (*a)->next->next->next->next->content;
	if ((*a)->content < t1 && t1 < t2 && t2 < t3 && t3 < t4)
		exit(0);
	else if (ft_min_4(t1, t2, t3, t4) == t1 && (*a)->content > t1)
		add_oper(oper, swap(*a, 'a'));
	else if (ft_min_4(t1, t2, t3, t4) == t2 && (*a)->content > t2)
		double_rotate_a(a, oper);
	else if (ft_min_4(t1, t2, t3, t4) == t3 && (*a)->content > t3)
		double_rev_rotate_a(a, oper);
	else if (ft_min_4(t1, t2, t3, t4) == t4 && (*a)->content > t4)
		add_oper(oper, rev_rotate(a, 'a'));
	add_oper(oper, push(b, a, 'b'));
	sort_for(a, b, oper);
	add_oper(oper, push(a, b, 'a'));
}
