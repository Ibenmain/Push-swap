/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimiser1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:16:00 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/14 16:16:14 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optim_sasa(t_oper **oper, int *flag, int *all)
{
	t_var	v;

	while (1)
	{
		*flag = 0;
		v.tmp = (*oper);
		while (v.tmp->next && v.tmp->next->next)
		{
			v.prev = v.tmp;
			v.fi = v.tmp->next;
			v.se = v.fi->next;
			if (ft_sequ(v.fi->data, "sa") && ft_sequ(v.se->data, "sa"))
			{
				*flag = 1;
				facl1(v.fi, v.se, v.prev, v.tmp);
			}
			else
				v.tmp = v.tmp->next;
		}
		if (*flag == 0)
			break ;
		else
			*all = 1;
	}
}

void	optim_sbsb(t_oper **oper, int *flag, int *all)
{
	t_var	v;

	while (1)
	{
		*flag = 0;
		v.tmp = (*oper);
		while (v.tmp->next && v.tmp->next->next)
		{
			v.prev = v.tmp;
			v.fi = v.tmp->next;
			v.se = v.fi->next;
			if (ft_sequ(v.fi->data, "sb") && ft_sequ(v.se->data, "sb"))
			{
				*flag = 1;
				facl1(v.fi, v.se, v.prev, v.tmp);
			}
			else
				v.tmp = v.tmp->next;
		}
		if (*flag == 0)
			break ;
		else
			*all = 1;
	}
}

void	optim_pbpa(t_oper **oper, int *flag, int *all)
{
	t_var	v;

	while (1)
	{
		*flag = 0;
		v.tmp = (*oper);
		while (v.tmp->next && v.tmp->next->next && v.tmp->next->next->next)
		{
			v.prev = v.tmp;
			v.fi = v.tmp->next;
			v.se = v.fi->next;
			if ((ft_sequ(v.fi->data, "pa") && ft_sequ(v.se->data, "pb"))
				|| (ft_sequ(v.fi->data, "pb") && ft_sequ(v.se->data, "pa")))
			{
				*flag = 1;
				facl1(v.fi, v.se, v.prev, v.tmp);
			}
			else
				v.tmp = v.tmp->next;
		}
		if (*flag == 0)
			break ;
		else
			*all = 1;
	}
}

void	optim_rrara(t_oper **oper, int *flag, int *all)
{
	t_var	v;

	while (1)
	{
		*flag = 0;
		v.tmp = (*oper);
		while (v.tmp->next && v.tmp->next->next)
		{
			v.prev = v.tmp;
			v.fi = v.tmp->next;
			v.se = v.fi->next;
			if ((ft_sequ(v.fi->data, "ra") && ft_sequ(v.se->data, "rra"))
				|| (ft_sequ(v.fi->data, "rra") && ft_sequ(v.se->data, "ra")))
			{
				*flag = 1;
				facl1(v.fi, v.se, v.prev, v.tmp);
			}
			else
				v.tmp = v.tmp->next;
		}
		if (*flag == 0)
			break ;
		else
			*all = 1;
	}
}

void	optim_rrbrb(t_oper **oper, int *flag, int *all)
{
	t_var	v;

	while (1)
	{
		*flag = 0;
		v.tmp = (*oper);
		while (v.tmp->next && v.tmp->next->next)
		{
			v.prev = v.tmp;
			v.fi = v.tmp->next;
			v.se = v.fi->next;
			if ((ft_sequ(v.fi->data, "rb") && ft_sequ(v.se->data, "rrb"))
				|| (ft_sequ(v.fi->data, "rrb") && ft_sequ(v.se->data, "rb")))
			{
				*flag = 1;
				facl1(v.fi, v.se, v.prev, v.tmp);
			}
			else
				v.tmp = v.tmp->next;
		}
		if (*flag == 0)
			break ;
		else
			*all = 1;
	}
}
