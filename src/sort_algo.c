/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:42:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/06 10:42:00 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two_to_tree(t_stacks *stacks)
{
	if (is_sort(stacks))
		return ;
	if (stacks->len_a == 2 && !is_sort((stacks)))
		ra(stacks);
	else if (stacks->stack_a[0] < stacks->stack_a[2]
		&& stacks->stack_a[2] < stacks->stack_a[1])
	{
		sa(stacks);
		ra(stacks);
	}
	else if (stacks->stack_a[2] < stacks->stack_a[0]
		&& stacks->stack_a[0] < stacks->stack_a[1])
		rra(stacks);
	else if (stacks->stack_a[1] < stacks->stack_a[0]
		&& stacks->stack_a[0] < stacks->stack_a[2])
		sa(stacks);
	else if (stacks->stack_a[1] < stacks->stack_a[2]
		&& stacks->stack_a[2] < stacks->stack_a[0])
		ra(stacks);
	else if (stacks->stack_a[2] < stacks->stack_a[1]
		&& stacks->stack_a[1] < stacks->stack_a[0])
	{
		sa(stacks);
		rra(stacks);
	}
}

void	send_small_b(t_stacks *stacks)
{
	int	i;
	int	min;
	int	index;

	i = 1;
	min = stacks->stack_a[0];
	while (i < stacks->len_a)
	{
		if (stacks->stack_a[i] < min)
			min = stacks->stack_a[i];
		i++;
	}
	index = find_index(stacks->stack_a, min);
	if (index <= stacks->len_a / 2)
		while (stacks->stack_a[0] != min)
			ra(stacks);
	else
		while (stacks->stack_a[0] != min)
			rra(stacks);
	pb(stacks);
}

void	sort_four_to_five(t_stacks *stacks)
{
	if (stacks->len_a == 5)
		send_small_b(stacks);
	send_small_b(stacks);
	sort_two_to_tree(stacks);
	while (stacks->stack_a[0] != 0)
		pa(stacks);
}

void	radix_sort(t_stacks *stacks)
{
	int	bit_shift;
	int	j;
	int	len;

	bit_shift = 0;
	while (!is_sort(stacks))
	{
		j = 0;
		len = stacks->len_a;
		while (j++ < len)
		{
			if ((stacks->stack_a[0] >> bit_shift) & 1)
				ra(stacks);
			else
				pb(stacks);
		}
		while (stacks->len_b)
			pa(stacks);
		bit_shift++;
	}
}
