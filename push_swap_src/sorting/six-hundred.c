/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six-hundred.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 10:31:49 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/31 16:33:47 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_median(t_stack stack)
{
	int		*dup;
	int		res;
	int		i;

	dup = malloc(sizeof(int) * stack.size);
	if (!dup)
		close_program(CLOSE_ERROR);
	i = stack.size;
	while (--i >= 0)
		dup[i] = stack.stack[i];
	sort_int_tab(dup, stack.size);
	res = dup[stack.size / 2];
	free(dup);
	return (res);
}

void		sort(t_checker *checker)
{
	int		min;
	int		max;
	
	while (checker->stack_b.size > 0)
	{
		min = get_min(checker->stack_b);
		max = get_max(checker->stack_b);
		if (checker->stack_b.stack[0] == min)
		{
			do_move(checker, "pa");
			do_move(checker, "ra");
		}
		else if (checker->stack_b.stack[0] == max)
			do_move(checker, "pa");
		else
			do_move(checker, "rb");
	}
}

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
		if (stack.stack[i] > max)
			return (true);	
	return (false);
}

void	sort_six_to_hundred(t_checker *checker)
{
	int		med;
	int		size;

	size = checker->stack_a.size;
	med = get_median(checker->stack_a);
	while (have_higher(checker->stack_a, med))
	{
		if (checker->stack_a.stack[0] < med)
			do_move(checker, "pb");
		else
			do_move(checker, "ra");
	}
	sort(checker);
	while (have_lower(checker->stack_a, med))
	{
		if (checker->stack_a.stack[0] > med)
			do_move(checker, "pb");
		else
			do_move(checker, "ra");
	}
	sort(checker);
	while (!is_sorted(checker->stack_a))
		do_move(checker, "ra");
}
