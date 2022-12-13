/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johan <johan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:25:30 by jprofit           #+#    #+#             */
/*   Updated: 2022/12/13 18:41:33 by johan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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

int	checklong(long )
{
	int	i;

	i = 0;
	while (i < stacks->len_a)
	{

	}
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
		ft_printf("%i\n", stacks->stack_a[i]);
		i++;
	}
	stacks->len_a = i;
	stacks->len_b = 0;
	if (checklong(stacks) || checkdup(stacks))
		ft_error(stacks);
}

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (argc > 1)
	{
		stacks = init_struct(argc);
		fill_struct(argc, argv, stacks);
		free_struct(stacks);
	}
	return (0);
}
