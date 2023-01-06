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

#include "../includes/push_swap.h"
#include "../libft/libft.h"

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
