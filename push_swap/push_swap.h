/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:21:03 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/17 23:45:53 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "my_checker/get_next_line.h"

typedef struct s_v
{
	int	x;
	int	y;
	int	z;
}	t_v;

typedef struct swap
{
	int			content;
	int			count;
	struct swap	*next;
}	t_swap;

typedef struct s_oper
{
	char			*data;
	struct s_oper	*next;
}	t_oper;

typedef struct s_var
{
	t_oper	*tmp;
	t_oper	*prev;
	t_oper	*fi;
	t_oper	*se;
}	t_var;

void	ft_check_space(char *str);
int		*ft_repet_nbr(char **spl, int count);
int		*ft_check_error(char **av, t_swap *data);
int		ft_count(char const *str, char d);
char	**ft_split(char const *s, char c);
char	**ft_other_split(char const *s, char c, int i, int j);
void	_free(char **tab);
void	print_stack(t_swap *lst);
void	print_table(int *tab);
void	msg_error(char *s);
int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, int start, int len);
int		ft_atoi(char *str);
t_swap	*ft_add_element(int agc, int *content);
void	ft_lstadd_back(t_swap **alst, t_swap *new);
void	ft_lstadd_front(t_swap **alst, t_swap *new);
t_swap	*ft_lstnew(int content);
void	ft_swap(int *a, int *b);
void	ft_lstdelone(t_swap **lst);
int		ft_check_sorted(t_swap *stack);
int		ft_lstsize(t_swap *lst);
void	ft_sorting(t_swap *stc_a, t_swap *stc_b, int size, t_oper **oper);
void	ft_sort_two(t_swap *stc_a, t_oper **oper);
void	ft_sort_three(t_swap *stc_a, t_oper **oper);
void	ft_sort_for(t_swap *stc_a, t_swap *stc_b, t_oper **oper);
int		ft_get_min(t_swap *stack);
int		ft_get_small_index4(t_swap *stack_a);
void	ft_find_small_number4(t_swap *stacks, t_oper **oper);
void	ft_sort_five(t_swap *stack_a, t_swap *stack_b, t_oper **oper);
int		ft_get_small_index5(t_swap *stack_a);
void	ft_find_small_number5(t_swap *stacks, t_oper **oper);
int		ft_sort_stack(t_swap **a, t_swap **b, int len, t_oper **oper);
int		ft_get_pivot(t_swap *a, int len);
void	ft_sort_table(int *t, int len);
void	ft_quick_sort_table(int *t, int first, int last);
void	add_oper(t_oper **head, char *data);
int		ft_sort_a(t_swap **a, int len, t_oper **oper);
int		ft_sort_b(t_swap **b, int len, t_oper **oper);
int		sort_b(t_swap **a, t_swap **b, int len, t_oper **oper);
void	back_b(t_swap **b, int r, t_oper **oper);
int		need_p(t_swap *head, int id, int len, int pivot);
void	ft_quick_sort_table(int *a, int low, int high);
int		partition(int *a, int low, int high);
int		ft_sort_asc(t_swap **a, int len, t_oper **oper);
int		ft_sort_desc(t_swap **b, int len, t_oper **oper);
void	ft_putstr(char const *s);
void	ft_putchar(char c);
void	ft_putendl(char const *s);
void	ft_strdel(char **as);
int		ft_sequ(char const *s1, char const *s2);
char	*ft_strdup(char	*src);
void	optim_operations(t_oper **oper);
void	optim_sasa(t_oper **oper, int *flag, int *all);
void	optim_sbsb(t_oper **oper, int *flag, int *all);
void	optim_pbpa(t_oper **oper, int *flag, int *all);
void	optim_rrara(t_oper **oper, int *flag, int *all);
void	optim_rrbrb(t_oper **oper, int *flag, int *all);
void	facl1(t_oper *fi, t_oper *se, t_oper *prev, t_oper *tmp);
void	facl2(t_oper *prev, t_oper *tmp);
void	optim_rarb(t_oper **oper, int *flag, int *all);
void	optim_sasb(t_oper **oper, int *flag, int *all);
void	optim_rrarrb(t_oper **oper, int *flag, int *all);
void	remove_oper(t_oper **head);
void	double_remove(t_oper *second, t_oper *first);
void	remove_ele(t_oper *head);
void	add_oper(t_oper **head, char *data);
void	print_operations(t_oper *oper);
void	clear_memory(t_swap **a, t_swap **b);
void	remove_stack(t_swap **head);
char	*swap(t_swap *head, char c);
char	*push(t_swap **a, t_swap **b, char c);
char	*rotate(t_swap **head, char c);
char	*rev_rotate(t_swap **lst, char c);
void	sort_five(t_swap **a, t_swap	**b, t_oper **oper);
void	double_rev_rotate_a(t_swap **a, t_oper **oper);
void	double_rotate_a(t_swap **a, t_oper **oper);
void	sort_for(t_swap **a, t_swap	**b, t_oper **oper);
int		ft_min_4(int t1, int t2, int t3, int t4);
void	sswap(t_swap *a, t_swap *b);
void	rrotate(t_swap **a, t_swap **b);
void	rrevrotate(t_swap **a, t_swap **b);

#endif