/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:36:28 by jprofit           #+#    #+#             */
/*   Updated: 2022/12/15 11:42:55 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"
#include "../libft/libft.h"

void	rra(t_stacks *stacks)
{
	int	temp;
	int	i;

	if (stacks->len_a < 2)
		return ;
	temp = stacks->stack_a[stacks->len_a - 1];
	i = stacks->len_a;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[i] = temp;
}

void	rrb(t_stacks *stacks)
{
	int	temp;
	int	i;

	if (stacks->len_b < 2)
		return ;
	temp = stacks->stack_b[stacks->len_b - 1];
	i = stacks->len_b;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[i] = temp;
}


void	rrr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
}
