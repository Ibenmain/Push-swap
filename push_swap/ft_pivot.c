/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:17:54 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 21:29:36 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_pivot(t_swap *a, int len)
{
	int	piv;
	int	*tab;
	int	i;

	i = 0;
	tab = (int *)malloc(sizeof(int) * len);
	if (!tab)
		return (0);
	while (i < len)
	{
		tab[i++] = a->content;
		a = a->next;
	}
	ft_quick_sort_table(tab, 0, len - 1);
	piv = tab[len / 2];
	free(tab);
	return (piv);
}
