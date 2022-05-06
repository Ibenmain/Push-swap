/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimiser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:15:39 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/14 16:15:43 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optim_operations(t_oper **oper)
{
	int		flag;
	int		all;

	all = 1;
	flag = 0;
	while (all && (*oper))
	{
		all = 0;
		optim_sasa(oper, &flag, &all);
		optim_sbsb(oper, &flag, &all);
		optim_pbpa(oper, &flag, &all);
		optim_rrara(oper, &flag, &all);
		optim_rrbrb(oper, &flag, &all);
		optim_rarb(oper, &flag, &all);
		optim_sasb(oper, &flag, &all);
		optim_rrarrb(oper, &flag, &all);
	}
}
