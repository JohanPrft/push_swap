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

#include "../includes/push_swap.h"
#include "../libft/libft.h"

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

t_stacks	*init_struct(int argc)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(*stacks));
	if (!stacks)
		ft_error(stacks);
	stacks->stack_a = malloc(sizeof(stacks->stack_a) * (argc - 1));
	if (!stacks->stack_a)
		ft_error(stacks);
	stacks->stack_b = malloc(sizeof(stacks->stack_b) * (argc - 1));
	if (!stacks->stack_b)
		ft_error(stacks);
	stacks->len_a = 0;
	stacks->len_b = 0;
	return (stacks);
}

t_stacks	*make_stacks(int argc, char **argv)
{
	int			i;
	t_stacks	*stacks;

	stacks = init_struct(argc);
	i = 0;
	while (argv[i + 1])
	{
		if (!ft_atoi_secure(argv[i + 1], &stacks->stack_a[i]))
			ft_error(stacks);
		i++;
	}
	stacks->len_a = i;
	stacks->len_b = 0;
	if (checkdup(stacks))
		ft_error(stacks);
	return (stacks);
}

char	**split_argv(char **argv)
{
	char	**tab;
	int		len;

	tab = ft_split(argv[1], ' ');
	len = 0;
	while (tab[len])
		len++;
	return (tab);
}

t_stacks	*make_stacks_and_parse(char **argv)
{
	char		**tab;
	t_stacks	*stacks;
	int			len;
	int			i;

	tab = split_argv(argv);
	len = 0;
	while (tab[len])
		len++;
	stacks = init_struct(len);
	i = 0;
	while (tab[i])
	{
		if (!ft_atoi_secure(tab[i], &stacks->stack_a[i]))
			ft_error(stacks);
		i++;
		stacks->len_a++;
	}
	split_free(tab, len);
	if (checkdup(stacks))
		ft_error(stacks);
	return (stacks);
}
