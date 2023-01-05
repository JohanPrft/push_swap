/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:25:30 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/04 14:36:32 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	free_struct(t_stacks *stacks)
{
	if (stacks != NULL)
	{
		free(stacks->stack_b);
		free(stacks->stack_a);
		free(stacks);
	}
}

void	ft_error(t_stacks *stacks)
{
	free_struct(stacks);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	printstruct(t_stacks *stacks)
{
	int	i;

	i = 0;
	ft_printf("\n--------- Stack A ---------\n");
	while (i < stacks->len_a)
	{
		ft_printf("%i ", stacks->stack_a[i]);
		i++;
	}
	ft_printf("\n--------- len = %i ---------\n", stacks->len_a);
	i = 0;
	ft_printf("\n--------- Stack B ---------\n");
	while (i < stacks->len_b)
	{
		ft_printf("%i ", stacks->stack_b[i]);
		i++;
	}
	ft_printf("\n--------- len = %i ---------\n\n", stacks->len_b);
}

void	sort_two_to_tree(t_stacks *stacks)
{
	if (stacks->len_a == 2 && !is_sort((stacks)))
		ra(stacks);
	else if (is_sort(stacks))
		;
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
		&& stacks->stack_a[3] < stacks->stack_a[0])
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
			rra(stacks);
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

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (argc > 1)
	{
		stacks = init_struct(argc);
		fill_struct(argc, argv, stacks);
		if (is_sort(stacks))
			exit (0);
		stacks->stack_a = convert_index(stacks);
		if (!stacks->stack_a)
			return (0);
		printstruct(stacks);
		if (stacks->len_a <= 3)
			sort_two_to_tree(stacks);
		else if (stacks->len_a <= 5)
			sort_four_to_five(stacks);
		else
			radix_sort(stacks);
		printstruct(stacks);
		free_struct(stacks);
	}
	return (0);
}
