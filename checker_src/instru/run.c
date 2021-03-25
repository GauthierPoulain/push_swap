/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:29:50 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/25 12:38:20 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	run_instru(t_checker *checker, char *instr)
{
	if (!ft_strcmp("sa", instr))
		swap_sa(checker);
	else if (!ft_strcmp("sb", instr))
		swap_sb(checker);
	else if (!ft_strcmp("ss", instr))
		swap_ss(checker);
	else if (!ft_strcmp("pa", instr))
		push_pa(checker);
	else if (!ft_strcmp("pb", instr))
		push_pb(checker);
	else if (!ft_strcmp("ra", instr))
		rotate_ra(checker);
	else if (!ft_strcmp("rb", instr))
		rotate_rb(checker);
	else if (!ft_strcmp("rr", instr))
		rotate_rr(checker);
	else if (!ft_strcmp("rra", instr))
		rotate_rra(checker);
	else if (!ft_strcmp("rrb", instr))
		rotate_rrb(checker);
	else if (!ft_strcmp("rrr", instr))
		rotate_rrr(checker);
	else
		close_checker(CLOSE_ERROR);
}
