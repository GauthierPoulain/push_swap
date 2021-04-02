/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 10:23:09 by gapoulai          #+#    #+#             */
/*   Updated: 2021/04/02 10:23:11 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_way(t_stack stack, int value)
{
	int		i;

	i = 0;
	while (i < stack.size && stack.stack[i] != value)
		i++;
	if (i < stack.size / 2)
		return (1);
	return (-1);
}

static void	sort(t_checker *checker)
{
	int		max;

	while (checker->stack_b.size > 0)
	{
		max = get_max(checker->stack_b);
		if (checker->stack_b.stack[0] == max)
			do_move(checker, "pa");
		else
		{
			if (get_way(checker->stack_b, max) == -1)
				do_move(checker, "rrb");
			else
				do_move(checker, "rb");
		}
	}
}

static void	sort_p2(t_checker *checker, int *cut, int pt)
{
	int		min;

	while (have_lower(checker->stack_a, cut[pt]))
	{
		if (checker->stack_a.stack[0] <= cut[pt])
			do_move(checker, "pb");
		else
		{
			min = get_min(checker->stack_a);
			if (get_way(checker->stack_b, min) == -1)
				do_move(checker, "ra");
			else
				do_move(checker, "rra");
		}
	}
}

void	sort_under_hundred(t_checker *checker)
{
	int		pt;
	int		*cut;

	cut = malloc(sizeof(int) * UNDER_H_SPLIT);
	if (!cut)
		close_program(CLOSE_ERROR);
	pt = -1;
	while (++pt < UNDER_H_SPLIT)
		cut[pt] = get_srt_index(checker->stack_a,
				(checker->stack_a.size / UNDER_H_SPLIT) * (pt + 1));
	pt = -1;
	while (++pt <= UNDER_H_SPLIT)
		sort_p2(checker, cut, pt);
	while (checker->stack_a.size > 0)
		do_move(checker, "pb");
	free(cut);
	sort(checker);
}

void	sort_over_hundred(t_checker *checker)
{
	int		pt;
	int		*cut;

	cut = malloc(sizeof(int) * OVER_H_SPLIT);
	if (!cut)
		close_program(CLOSE_ERROR);
	pt = -1;
	while (++pt < OVER_H_SPLIT)
		cut[pt] = get_srt_index(checker->stack_a,
			(checker->stack_a.size / OVER_H_SPLIT) * (pt + 1));
	pt = -1;
	while (++pt <= OVER_H_SPLIT)
		sort_p2(checker, cut, pt);
	while (checker->stack_a.size > 0)
		do_move(checker, "pb");
	free(cut);
	sort(checker);
}
