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
	free(stacks->stack_b);
	free(stacks->stack_a);
	free(stacks);
}

void	ft_error(t_stacks *stacks)
{
	if (stacks && stacks->stack_b)
		free(stacks->stack_b);
	if (stacks && stacks->stack_a)
		free(stacks->stack_a);
	if (stacks)
		free(stacks);
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

	if (argc == 2)
		stacks = make_stacks_and_parse(argv);
	else
		stacks = make_stacks(argc, argv);
	if (is_sort(stacks))
	{
		free_struct(stacks);
		return (0);
	}
	make_stack_index(stacks);
	if (stacks->len_a <= 3)
		sort_two_to_tree(stacks);
	else if (stacks->len_a <= 5)
		sort_four_to_five(stacks);
	else
		radix_sort(stacks);
	free_struct(stacks);
	return (0);
}
