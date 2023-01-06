/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:54:32 by jprofit           #+#    #+#             */
/*   Updated: 2022/12/14 17:06:41 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '+' || c == '-')
		return (1);
	return (0);
}

int	strisdigit(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	checkforint(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!strisdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	checklong(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->len_a)
	{
		if (INT_MIN > stacks->stack_a[i] || INT_MAX < stacks->stack_a[i])
			return (1);
		i++;
	}
	return (0);
}

int	checkdup(t_stacks *stacks)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	while (i < stacks->len_a)
	{
		nb = stacks->stack_a[i];
		j = i + 1;
		while (j < stacks->len_a)
		{
			if (nb == stacks->stack_a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
