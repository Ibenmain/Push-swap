/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:21:33 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 23:05:03 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_swap *lst)
{
	t_swap	*tmp;
	int		size;

	size = 0;
	tmp = lst;
	if (!tmp)
		return (0);
	else
	{
		while (tmp != NULL)
		{
			size++;
			tmp = tmp->next;
		}
	}
	return (size);
}

void	ft_sorting(t_swap *stc_a, t_swap *stc_b, int size, t_oper **oper)
{
	if (size < 2)
		return ;
	if (size == 2)
		ft_sort_two(stc_a, oper);
	if (size == 3)
		ft_sort_three(stc_a, oper);
	if (size == 4)
		sort_for(&stc_a, &stc_b, oper);
	if (size == 5)
		sort_five(&stc_a, &stc_b, oper);
	if (size >= 6)
		ft_sort_stack(&stc_a, &stc_b, size, oper);
}
