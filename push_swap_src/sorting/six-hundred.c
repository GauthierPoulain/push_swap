/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six-hundred.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 10:31:49 by gapoulai          #+#    #+#             */
/*   Updated: 2021/04/01 13:25:35 by gapoulai         ###   ########lyon.fr   */
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

int	get_way(t_stack stack, int min)
{
	int		i;

	i = 0;
	while (i < stack.size && stack.stack[i] != min)
		i++;
	if (i < stack.size / 2)
		return (1);
	return (-1);
}

void	sort(t_checker *checker)
{
	int		min;
	int		max;

	while (checker->stack_b.size > 0)
	{
		min = get_min(checker->stack_b);
		max = get_max(checker->stack_b);
		if (checker->stack_b.stack[0] <= min)
		{
			do_move(checker, "pa");
			do_move(checker, "ra");
		}
		else if (checker->stack_b.stack[0] >= max)
			do_move(checker, "pa");
		else
		{
			if (get_way(checker->stack_b, min) == -1)
				do_move(checker, "rrb");
			else
				do_move(checker, "rb");
		}
	}
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
		if (checker->stack_a.stack[0] >= med)
			do_move(checker, "pb");
		else
			do_move(checker, "ra");
	}
	sort(checker);
	while (!is_sorted(checker->stack_a))
		do_move(checker, "ra");
}
