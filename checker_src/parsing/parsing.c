/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:05:40 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/24 14:13:09 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static bool	exist(t_stack stack, int value)
{
	int	i;

	i = -1;
	while (++i < stack.size)
		if (stack.stack[i] == value)
			return (true);
	return (false);
}

static void	fill_stack_a(t_checker *checker, int argc, char **argv)
{
	int		i;

	checker->stack_a.stack = malloc(sizeof(int) * (argc - 1));
	if (!checker->stack_a.stack)
		close_checker(CLOSE_ERROR);
	checker->stack_a.stack = checker->stack_a.stack;
	i = 1;
	while (i < argc)
	{
		checker->stack_a.stack[i - 1] = ft_atoi(argv[i]);
		if (exist(checker->stack_a, checker->stack_a.stack[i - 1]))
			close_checker(CLOSE_ERROR);
		checker->stack_a.size = i;
		i++;
	}
}

static void	fill_stack_b(t_checker *checker)
{
	int		i;

	checker->stack_b.stack = malloc(sizeof(int) * checker->stack_a.size);
	if (!checker->stack_b.stack)
		close_checker(CLOSE_ERROR);
	i = 0;
	while (i < checker->stack_a.size)
	{
		checker->stack_b.stack[i] = checker->stack_a.stack[i];
		i++;
	}
	checker->stack_b.size = 10;
}

void	parsing(t_checker *checker, int argc, char **argv)
{
	parsing_check(argc, argv);
	fill_stack_a(checker, argc, argv);
	fill_stack_b(checker);
}
