/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:10:05 by gapoulai          #+#    #+#             */
/*   Updated: 2021/04/02 03:08:57 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	have_higher(t_stack stack, int min)
{
	int		i;

	i = -1;
	while (++i < stack.size)
		if (stack.stack[i] < min)
			return (true);
	return (false);
}

bool	have_lower(t_stack stack, int max)
{
	int		i;

	i = -1;
	while (++i < stack.size)
		if (stack.stack[i] >= max)
			return (true);
	return (false);
}

bool	have_inrange(t_stack stack, int min, int max)
{
	int		i;

	i = -1;
	while (++i < stack.size)
		if (stack.stack[i] >= min && stack.stack[i] <= max)
			return (true);
	return (false);
}

bool	have_outrange(t_stack stack, int min, int max)
{
	int		i;

	i = -1;
	while (++i < stack.size)
		if (stack.stack[i] < min || stack.stack[i] > max)
			return (true);
	return (false);
}
