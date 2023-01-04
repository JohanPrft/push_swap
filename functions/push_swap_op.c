/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:34:10 by jprofit           #+#    #+#             */
/*   Updated: 2022/12/15 10:38:04 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	sa(t_stacks *stacks)
{
	int	temp;

	if (stacks->len_a < 2)
		return ;
	temp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stacks *stacks)
{
	int	temp;

	if (stacks->len_b < 2)
		return ;
	temp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
	write(1, "ss\n", 3);
}



