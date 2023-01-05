/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:13:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/03 09:13:00 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int	is_sort(t_stacks *stacks)
{
	int	i;

	i = 1;
	while (i < stacks->len_a)
	{
		if (stacks->stack_a[i] < stacks->stack_a[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	find_max_without(long *array, int len, int nb)
{
	int	max;
	int	i;

	max = 0;
	while (max < len)
	{
		if (array[max] < nb)
			break ;
		max++;
	}
	max = array[max];
	i = 1;
	while (i < len)
	{
		if (array[i] > max && array[i] < nb)
			max = array[i];
		i++;
	}
	return (max);
}

int	find_index(long *array, int nb)
{
	int	i;

	i = 0;
	while (array[i] != nb)
		i++;
	return (i);
}

long	*convert_index(t_stacks *stacks)
{
	long	*index;
	int		max;
	int		count;
	int		i;

	index = malloc(sizeof(*index) * stacks->len_a);
	if (!index)
	{
		free_struct(stacks);
		return (NULL);
	}
	i = 0;
	max = stacks->stack_a[0];
	while (++i < stacks->len_a)
		if (max < stacks->stack_a[i])
			max = stacks->stack_a[i];
	count = stacks->len_a - 1;
	index[find_index(stacks->stack_a, max)] = count;
	while (--count >= 0)
	{
		max = find_max_without(stacks->stack_a, stacks->len_a, max);
		index[find_index(stacks->stack_a, max)] = count;
	}
	free(stacks->stack_a);
	return (index);
}
