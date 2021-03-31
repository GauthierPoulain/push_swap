/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:36:05 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/31 11:22:05 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_int_tab(int *tab, int size)
{
	bool	sorted;
	int		i;

	sorted = false;
	while (!sorted)
	{
		sorted = true;
		i = -1;
		while (++i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				sorted = false;
			}
		}
	}
}

int	get_min(t_stack stack)
{
	int		min;
	int		i;

	min = stack.stack[0];
	i = 0;
	while (i < stack.size)
	{
		if (stack.stack[i] < min)
			min = stack.stack[i];
		i++;
	}
	return (min);
}

int	get_max(t_stack stack)
{
	int		max;
	int		i;

	max = stack.stack[0];
	i = 0;
	while (i < stack.size)
	{
		if (stack.stack[i] > max)
			max = stack.stack[i];
		i++;
	}
	return (max);
}

int		ft_abs(int nb)
{
	if (nb > 0)
		return (nb);
	return (nb * -1);
}

int		get_closer(t_stack stack, int value)
{
	int		closer;
	int		i;

	closer = stack.stack[0];
	i = 0;
	while (i < stack.size)
	{
		if (ft_abs(value - stack.stack[i]) < ft_abs(value - closer))
			closer = stack.stack[i];
		i++;
	}
	return (closer);
}
