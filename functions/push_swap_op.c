/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:34:10 by jprofit           #+#    #+#             */
/*   Updated: 2022/12/14 18:18:18 by jprofit          ###   ########.fr       */
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
}

void	sb(t_stacks *stacks)
{
	int	temp;

	if (stacks->len_b < 2)
		return ;
	temp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = temp;
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}



void	pb(t_stacks *stacks)
{
	int	i;

	if (stacks->len_a < 1)
		return ;
	i = stacks->len_b;
	while (i > 1)
	{
		stacks->stack_b[i + 1] = stacks->stack_b[i];
		i--;
	}
	stacks->len_b++;
	stacks->stack_b[0] = stacks->stack_a[0];
	i = 0;
	while (i < stacks->len_a)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->len_a--;
}