/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:19:42 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 21:41:38 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_swap *stc_a, t_oper **oper)
{
	if (stc_a->content > stc_a->next->content)
		add_oper(oper, swap(stc_a, 'a'));
	else
		return ;
}
