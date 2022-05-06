/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 02:10:28 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 23:47:40 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s2)
		return (1);
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

void	break_programm(t_swap **a, t_swap **b)
{
	clear_memory(a, b);
	write(2, "Error\n", 6);
	exit(0);
}

void	init_commands(char *comm, t_swap **a, t_swap **b)
{
	if (!ft_strcmp(comm, "sa\n"))
		swap(*a, 'a');
	else if (!ft_strcmp(comm, "sb\n"))
		swap(*b, 'b');
	else if (!ft_strcmp(comm, "ss\n"))
		sswap(*a, *b);
	else if (!ft_strcmp(comm, "pa\n"))
		push(a, b, 'a');
	else if (!ft_strcmp(comm, "pb\n"))
		push(b, a, 'b');
	else if (!ft_strcmp(comm, "ra\n"))
		rotate(a, 'a');
	else if (!ft_strcmp(comm, "rb\n"))
		rotate(b, 'b');
	else if (!ft_strcmp(comm, "rr\n"))
		rrotate(a, b);
	else if (!ft_strcmp(comm, "rra\n"))
		rev_rotate(a, 'a');
	else if (!ft_strcmp(comm, "rrb\n"))
		rev_rotate(b, 'b');
	else if (!ft_strcmp(comm, "rrr\n"))
		rrevrotate(a, b);
	else
		break_programm(a, b);
}

void	read_commands(t_swap **a, t_swap **b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		init_commands(line, a, b);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_swap	*a;
	t_swap	*b;
	int		*tab;

	a = NULL;
	b = NULL;
	if (ac >= 2)
	{
		tab = ft_check_error(av, a);
		a = ft_add_element(ac - 1, tab);
		free(tab);
		read_commands(&a, &b);
		if (ft_check_sorted(a) && !b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	return (0);
}
