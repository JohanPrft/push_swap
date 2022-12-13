/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johan <johan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:19:00 by jprofit           #+#    #+#             */
/*   Updated: 2022/12/13 18:42:33 by johan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <stdlib.h>
// # include <stdarg.h>
# include <unistd.h>

typedef struct s_stacks
{
	long	*stack_a;
	int		len_a;
	int		*stack_b;
	int		len_b;
}	t_stacks;

#endif
