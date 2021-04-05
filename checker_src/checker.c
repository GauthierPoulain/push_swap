/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 03:02:14 by gapoulai          #+#    #+#             */
/*   Updated: 2021/04/05 15:43:17 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

void	run_instru(t_checker *checker, char *move)
{
	if (!ft_strcmp("sa", move))
		swap_sa(checker);
	else if (!ft_strcmp("sb", move))
		swap_sb(checker);
	else if (!ft_strcmp("ss", move))
		swap_ss(checker);
	else if (!ft_strcmp("pa", move))
		push_pa(checker);
	else if (!ft_strcmp("pb", move))
		push_pb(checker);
	else if (!ft_strcmp("ra", move))
		rotate_ra(checker);
	else if (!ft_strcmp("rb", move))
		rotate_rb(checker);
	else if (!ft_strcmp("rr", move))
		rotate_rr(checker);
	else if (!ft_strcmp("rra", move))
		rotate_rra(checker);
	else if (!ft_strcmp("rrb", move))
		rotate_rrb(checker);
	else if (!ft_strcmp("rrr", move))
		rotate_rrr(checker);
	else
		close_program(CLOSE_ERROR);
}

int	main(int argc, char **argv)
{
	t_checker	checker;

	if (argc == 1)
		close_program(CLOSE_NOPRINT);
	parsing(&checker, argc, argv);
	get_instru(&checker);
	if (is_sorted(checker.stack_a))
		close_program(CLOSE_OK);
	close_program(CLOSE_KO);
}
