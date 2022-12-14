/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:53:17 by jprofit           #+#    #+#             */
/*   Updated: 2022/12/14 17:22:11 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

t_stacks	*init_struct(int argc)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(*stacks));
	if (!stacks)
		return (NULL);
	stacks->stack_a = malloc(sizeof(stacks->stack_a) * (argc - 1));
	if (!stacks->stack_a)
	{
		free(stacks);
		return (NULL);
	}
	stacks->stack_b = malloc(sizeof(stacks->stack_b) * (argc - 1));
	if (!stacks->stack_b)
	{
		free(stacks->stack_a);
		free(stacks);
		return (NULL);
	}
	return (stacks);
}

void	fill_struct(int argc, char *argv[], t_stacks *stacks)
{
	int	i;

	if (!checkforint(argc, argv))
		ft_error(stacks);
	i = 0;
	while (argv[i + 1])
	{
		stacks->stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	stacks->len_a = i;
	stacks->len_b = 0;
	if (checklong(stacks) || checkdup(stacks))
		ft_error(stacks);
}
