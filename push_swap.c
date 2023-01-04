/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:25:30 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/04 11:35:45 by jprofit          ###   ########.fr       */
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

void	ra(t_stacks *stacks)
{
	int	temp;
	int	i;

	if (stacks->len_a < 2)
		return ;
	temp = stacks->stack_a[0];
	i = 0;
	while (i < stacks->len_a - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->stack_a[i] = temp;
	write(1, "ra\n", 3);
}

void	pa(t_stacks *stacks)
{
	int	i;

	if (stacks->len_b < 1)
		return ;
	i = stacks->len_a;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = stacks->stack_b[0];
	stacks->len_a++;
	i = 0;
	while (i < stacks->len_b)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->len_b--;
	write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks)
{
	int	i;

	if (stacks->len_a < 1)
		return ;
	i = stacks->len_b;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = stacks->stack_a[0];
	stacks->len_b++;
	i = 0;
	while (i < stacks->len_a)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->len_a--;
	write(1, "pb\n", 3);
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
		stacks->stack_a = convert_index(stacks);
		if (!stacks->stack_a)
			return (0);
		//printstruct(stacks);
		radix_sort(stacks);
		//printstruct(stacks);
		free_struct(stacks);
	}
	return (0);
}


