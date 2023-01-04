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
// # include <stdarg.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stacks
{
	long	*stack_a;
	int		len_a;
	int		*stack_b;
	int		len_b;
}	t_stacks;

int			ft_isdigit(int c);
int			strisdigit(const char *str);
int			checkforint(int argc, char *argv[]);
int			checklong(t_stacks *stacks);
int			checkdup(t_stacks *stacks);

t_stacks	*init_struct(int argc);
void		fill_struct(int argc, char *argv[], t_stacks *stacks);
void		free_struct(t_stacks *stacks);
void		ft_error(t_stacks *stacks);
void		swap_a(t_stacks *stacks);

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

int			is_sort(t_stacks *stacks);
int			find_max_without(long *array, int len, int nb);
int			find_index(long *array, int nb);
long		*convert_index(t_stacks *stacks);

#endif
