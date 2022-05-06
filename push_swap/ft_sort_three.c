/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:19:30 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 21:40:58 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_swap *stc_a, t_oper **oper)
{
	if (stc_a->content > stc_a->next->content)
		add_oper(oper, swap(stc_a, 'a'));
	if (!ft_check_sorted(stc_a))
		add_oper(oper, rev_rotate(&stc_a, 'a'));
	if (stc_a->content > stc_a->next->content)
		add_oper(oper, swap(stc_a, 'a'));
}
