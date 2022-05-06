/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:19:21 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 21:40:17 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	need_p(t_swap *head, int id, int len, int pivot)
{
	t_swap	*ptr;

	ptr = head;
	while (len--)
	{
		if (id == 1 && ptr->content < pivot)
			return (1);
		else if (id == 2 && ptr->content > pivot)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

void	back_a(t_swap **a, int r, t_oper **oper)
{
	if (r > ft_lstsize(*a) / 2)
		while (ft_lstsize(*a) - r++ > 0)
			add_oper(oper, rotate(a, 'a'));
	else
		while (r--)
			add_oper(oper, rev_rotate(a, 'a'));
}

int	ft_sort_stack(t_swap **a, t_swap **b, int len, t_oper **oper)
{
	int		pivot;
	int		p;
	int		r;
	int		i;

	r = 0;
	i = 0;
	p = 0;
	if (len <= 3)
		return (ft_sort_a(a, len, oper));
	pivot = ft_get_pivot(*a, len);
	while (need_p(*a, 1, len - i, pivot) && i++ < len)
	{
		if ((*a)->content < pivot && ++p)
			add_oper(oper, push(b, a, 'b'));
		else if ((*a)->content >= pivot && ++r)
			add_oper(oper, rotate(a, 'a'));
	}
	back_a(a, r, oper);
	ft_sort_stack(a, b, len - p, oper);
	sort_b(a, b, p, oper);
	while (p--)
		add_oper(oper, push(a, b, 'a'));
	return (0);
}

void	back_b(t_swap **b, int r, t_oper **oper)
{
	if (r > ft_lstsize(*b) / 2)
		while (ft_lstsize(*b) - r++ > 0)
			add_oper(oper, rotate(b, 'b'));
	else
		while (r--)
			add_oper(oper, rev_rotate(b, 'b'));
}

int	sort_b(t_swap **a, t_swap **b, int len, t_oper **oper)
{
	int		pivot;
	int		p;
	int		r;
	int		i;

	r = 0;
	i = 0;
	p = 0;
	if (len <= 3)
		return (ft_sort_b(b, len, oper));
	pivot = ft_get_pivot(*b, len);
	while (need_p(*b, 2, len - i, pivot) && i++ < len)
	{
		if ((*b)->content > pivot && ++p)
			add_oper(oper, push(a, b, 'a'));
		else if ((*b)->content <= pivot && ++r)
			add_oper(oper, rotate(b, 'b'));
	}
	ft_sort_stack(a, b, p, oper);
	back_b(b, r, oper);
	sort_b(a, b, len - p, oper);
	while (p--)
		add_oper(oper, push(b, a, 'b'));
	return (0);
}
