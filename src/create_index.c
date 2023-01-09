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

#include "../includes/push_swap.h"
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

int	find_max(const int *array, int len)
{
	int	max;
	int	i;

	i = -1;
	max = array[0];
	while (++i < len)
		if (array[i] > max)
			max = array[i];
	return (max);
}

int	find_max_inferior(const int *array, int len, int nb)
{
	int	max;
	int	i;

	i = -1;
	while (++i < len)
		if (array[i] < nb)
			break ;
	max = array[i];
	i = -1;
	while (++i < len)
		if (array[i] > max && array[i] < nb)
			max = array[i];
	return (max);
}

//array numbers must be unique
int	find_index(const int *array, int nb)
{
	int	i;

	i = 0;
	while (array[i] != nb)
		i++;
	return (i);
}

void	make_stack_index(t_stacks *stacks)
{
	int		*index;
	int		max;
	int		count;

	index = malloc(sizeof(*index) * stacks->len_a);
	if (!index)
		ft_error(stacks);
	max = find_max(stacks->stack_a, stacks->len_a);
	count = stacks->len_a - 1;
	index[find_index(stacks->stack_a, max)] = count;
	while (--count >= 0)
	{
		max = find_max_inferior(stacks->stack_a, stacks->len_a, max);
		index[find_index(stacks->stack_a, max)] = count;
	}
	free(stacks->stack_a);
	stacks->stack_a = index;
}
