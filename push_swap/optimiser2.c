/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimiser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:16:36 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/14 16:17:45 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	facl1(t_oper *fi, t_oper *se, t_oper *prev, t_oper *tmp)
{
	prev->next = se->next;
	double_remove(se, fi);
	tmp = prev->next;
}

void	facl2(t_oper *prev, t_oper *tmp)
{
	prev->next = tmp->next;
	ft_strdel(&tmp->data);
	ft_strdel(&tmp->next->data);
}

void	optim_rarb(t_oper **oper, int *flag, int *all)
{
	t_var	v;

	while (1)
	{
		*flag = 0;
		v.tmp = (*oper);
		while (v.tmp->next)
		{
			if ((ft_sequ(v.tmp->data, "ra") && ft_sequ(v.tmp->next->data, "rb"))
				|| (ft_sequ(v.tmp->data, "rb")
					&& ft_sequ(v.tmp->next->data, "ra")))
			{
				*flag = 0;
				facl2(v.prev, v.tmp);
				v.tmp->next->data = ft_strdup("rr");
			}
			v.prev = v.tmp;
			v.tmp = v.tmp->next;
		}
		if (*flag == 0)
			break ;
		else
			*all = 1;
	}
}

void	optim_sasb(t_oper **oper, int *flag, int *all)
{
	t_var	v;

	while (1)
	{
		*flag = 0;
		v.tmp = (*oper);
		while (v.tmp->next)
		{
			if ((ft_sequ(v.tmp->data, "sa") && ft_sequ(v.tmp->next->data, "sb"))
				|| (ft_sequ(v.tmp->data, "sb")
					&& ft_sequ(v.tmp->next->data, "sa")))
			{
				*flag = 0;
				facl2(v.prev, v.tmp);
				v.tmp->next->data = ft_strdup("ss");
			}
			v.prev = v.tmp;
			v.tmp = v.tmp->next;
		}
		if (*flag == 0)
			break ;
		else
			*all = 1;
	}
}

void	optim_rrarrb(t_oper **oper, int *flag, int *all)
{
	t_var	v;

	while (1)
	{
		*flag = 0;
		v.tmp = (*oper);
		while (v.tmp->next)
		{
			if ((ft_sequ(v.tmp->data, "rra")
					&& ft_sequ(v.tmp->next->data, "rrb"))
				|| (ft_sequ(v.tmp->data, "rrb")
					&& ft_sequ(v.tmp->next->data, "rra")))
			{
				*flag = 0;
				facl2(v.prev, v.tmp);
				v.tmp->next->data = ft_strdup("rrr");
			}
			v.prev = v.tmp;
			v.tmp = v.tmp->next;
		}
		if (*flag == 0)
			break ;
		else
			*all = 1;
	}
}
