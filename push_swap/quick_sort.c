/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:21:09 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 21:47:48 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *a, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = a[high];
	i = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		if (a[j] < pivot)
		{
			i++;
			ft_swap(&a[i], &a[j]);
		}
		j++;
	}
	ft_swap(&a[i + 1], &a[high]);
	return (i + 1);
}

void	ft_quick_sort_table(int *a, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(a, low, high);
		ft_quick_sort_table(a, low, pi - 1);
		ft_quick_sort_table(a, pi + 1, high);
	}
}
