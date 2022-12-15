/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:25:30 by jprofit           #+#    #+#             */
/*   Updated: 2022/12/15 11:41:32 by jprofit          ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (argc > 1)
	{
		stacks = init_struct(argc);
		fill_struct(argc, argv, stacks);
		pb(stacks);
		pb(stacks);
		printstruct(stacks);
		rra(stacks);
		printstruct(stacks);
		free_struct(stacks);
	}
	return (0);
}
