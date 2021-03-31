/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six-hundred.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 10:31:49 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/31 11:15:57 by gapoulai         ###   ########lyon.fr   */
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
		close_push_swap(CLOSE_ERROR);
	i = stack.size;
	while (--i >= 0)
		dup[i] = stack.stack[i];
	sort_int_tab(dup, stack.size);
	res = dup[stack.size / 2];
	free(dup);
	return (res);
}



static void		sort(t_checker *checker)
{
	int		min;
	int		max;
	
	while (checker->stack_b.size > 0)
	{
		min = get_min(checker->stack_a);
		max = get_max(checker->stack_a);
		
		
	}
}

void	sort_six_to_hundred(t_checker *checker)
{
	int		med;
	int		i;
	int		size;


	size = checker->stack_a.size;
	med = get_median(checker->stack_a);
	i = 0;
	while (i < size)
	{
		if (checker->stack_a.stack[0] < med)
			do_move(checker, "pb");
		else
		{
			do_move(checker, "ra");
			i++;
		}
		print_stacks(checker);
	}
	sort(checker);
}
