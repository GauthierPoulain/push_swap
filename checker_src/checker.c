/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 03:02:14 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/30 13:34:34 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

void	print_stacks(t_checker *checker)
{
	int		i;
	int		min;

	if (checker->stack_a.size < checker->stack_b.size)
		min = checker->stack_b.size;
	else
		min = checker->stack_a.size;
	i = 0;
	printf("|----------------------------------------------------|\n");
	printf("|id    |stack a               |stack b               |\n");
	printf("|      |size : %-15zd|size : %-15zd|\n", checker->stack_a.size,
		checker->stack_b.size);
	printf("|----------------------------------------------------|\n");
	while (i < min)
	{
		printf("|%-6d|%-22d|%-22d|\n", i, checker->stack_a.stack[i],
			checker->stack_b.stack[i]);
		i++;
	}
	printf("|----------------------------------------------------|\n");
}

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

bool	is_sorted(t_checker *checker)
{
	int		i;

	i = -1;
	while (++i < checker->stack_a.size - 1)
		if (checker->stack_a.stack[i] >= checker->stack_a.stack[i + 1])
			return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_checker	checker;

	parsing(&checker, argc, argv);
	if (PRINT_STACKS)
		print_stacks(&checker);
	get_instru(&checker);
	if (is_sorted(&checker))
		close_checker(CLOSE_OK);
	close_checker(CLOSE_KO);
}
