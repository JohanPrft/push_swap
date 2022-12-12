/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:25:30 by jprofit           #+#    #+#             */
/*   Updated: 2022/12/12 16:33:27 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	else
		return (0);
}

int	nb_digit(char *list)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (list[i])
	{
		if (!ft_isdigit(list[i]) && !ft_iswhitespace(list[i]))
			return (-1);
		while (ft_isdigit(list[i]))
			i++;
		nb++;
		while (ft_iswhitespace(list[i]))
			i++;
	}
	return (nb);
}

int	list_check(char *list)
{
	int	i;
	int	nb;

	i = 0;
	nb = nb_digit(list);
	return (nb);
}

int	*make_list(char *argv[], int argc)
{
	int	i;
	int	*list;

	i = 0;
	list = malloc(sizeof(*list) * (argc + 1));
	while (i < argc - 1)
	{
		list[i] = ft_atoi(argv[i + 1]);
		ft_printf("%i\n", list[i]);
		i++;
	}
	list[i] = 0;
	ft_printf("%i\n", list[i]);
	return (list);
}

int	*manage_argv(char *argv[], int argc)
{
	if (argc > 1)
		return (make_list(argv, argc));
	return (0);
}

int	main(int argc, char *argv[])
{
	manage_argv(argv, argc);
	return (0);
}
