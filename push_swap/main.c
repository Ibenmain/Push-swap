/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:20:38 by ibenmain          #+#    #+#             */
/*   Updated: 2022/05/06 14:47:54 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_swap **stack_a)
{
	t_swap	*tmp;

	if (stack_a)
	{
		while (stack_a)
		{
			tmp = (*stack_a)->next;
			free(stack_a);
			*stack_a = tmp;
		}
		*stack_a = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_swap	*stack_a;
	t_swap	*stack_b;
	t_oper	*oper;
	int		*tab;

	(void)argc;
	stack_a = malloc(sizeof(t_swap));
	stack_b = NULL;
	tab = ft_check_error(argv, stack_a);
	stack_a = ft_add_element(stack_a->count, tab);
	free(tab);
	if (ft_check_sorted(stack_a) && stack_b == NULL)
		exit(0);
	ft_sorting(stack_a, stack_b, ft_lstsize(stack_a), &oper);
	optim_operations(&oper);
	print_operations(oper);
	remove_oper(&oper);
	remove_stack(&stack_b);
	remove_stack(&stack_a);
}
