/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:18:17 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 21:29:46 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putendl(char const *s)
{
	if (!s)
		return ;
	ft_putstr(s);
	ft_putchar('\n');
}

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar(*s++);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
