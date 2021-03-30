/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 03:02:14 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/30 15:26:02 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

void	close_checker(int code)
{
	if (code == CLOSE_ERROR)
	{
		ft_print_err("Error\n");
		exit(EXIT_FAILURE);
	}
	else if (code == CLOSE_OK)
	{
		printf("OK\n");
		exit(EXIT_SUCCESS);
	}
	else if (code == CLOSE_KO)
	{
		printf("KO\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("unhandled close code\n");
		exit(EXIT_FAILURE);
	}
}

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
		close_checker(CLOSE_ERROR);
}

int	main(int argc, char **argv)
{
	t_checker	checker;

	parsing(&checker, argc, argv);
	if (PRINT_STACKS)
		print_stacks(&checker);
	if (is_sorted(&checker))
		close_checker(CLOSE_OK);
	get_instru(&checker);
	if (is_sorted(&checker))
		close_checker(CLOSE_OK);
	close_checker(CLOSE_KO);
}
