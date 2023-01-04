/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:56:54 by jprofit           #+#    #+#             */
/*   Updated: 2022/12/15 11:31:15 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"



void	rb(t_stacks *stacks)
{
	int	temp;
	int	i;

	if (stacks->len_b < 2)
		return ;
	temp = stacks->stack_b[0];
	i = 0;
	while (i < stacks->len_b - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[i] = temp;
	write(1, "rb\n", 3);
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
	write(1, "rr\n", 3);
}
