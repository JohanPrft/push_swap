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

int	ft_atoi_secure(const char *str, int *var)
{
	long	res;
	long	sign;
	size_t	i;

	sign = 1;
	res = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		if (res + (sign < 0) > INT_MAX)
			return (0);
		i++;
	}
	if (!i || i != ft_strlen(str) || (i == 1 && sign < 0))
		return (0);
	*var = sign * res;
	return (1);
}
