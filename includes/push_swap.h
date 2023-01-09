/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:19:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/02 09:44:32 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stacks
{
	int	*stack_a;
	int	len_a;
	int	*stack_b;
	int	len_b;
}	t_stacks;

void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);

void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);

void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);

void		ft_error(t_stacks *stacks);
void		printstruct(t_stacks *stacks);

int			ft_atoi_secure(const char *str, int *var);

t_stacks	*make_stacks(int argc, char **argv);
t_stacks	*make_stacks_and_parse(char **argv);

int			is_sort(t_stacks *stacks);
int			find_index(const int *array, int nb);
void		make_stack_index(t_stacks *stacks);

void		sort_two_to_tree(t_stacks *stacks);
void		sort_four_to_five(t_stacks *stacks);
void		radix_sort(t_stacks *stacks);

#endif
