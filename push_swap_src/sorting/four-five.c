/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four-five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:38:39 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/30 10:30:03 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_2_mins(t_checker *checker)
{
	int		min;
	int		id;
	int		i;

	min = checker->stack_a.stack[0];
	i = -1;
	id = 0;
	while (++i < checker->stack_a.size)
	{
		if (checker->stack_a.stack[i] < min)
		{
			id = i;
			min = checker->stack_a.stack[i];
		}
	}
	if (i < checker->stack_a.size / 2)
		while (checker->stack_a.stack[0] != min)
			do_move(checker, "ra");
	else
		while (checker->stack_a.stack[0] != min)
			do_move(checker, "rra");
	do_move(checker, "pb");
	if (checker->stack_b.size == 1)
		push_2_mins(checker);
}

void	sort_four_five(t_checker *checker)
{
	push_2_mins(checker);
	if (checker->stack_a.size == 2 && !is_sorted(checker->stack_a))
		do_move(checker, "ra");
	else if (!is_sorted(checker->stack_a))
		sort_three(checker);
	if (is_sorted(checker->stack_b))
		do_move(checker, "rb");
	do_move(checker, "pa");
	do_move(checker, "pa");
}
