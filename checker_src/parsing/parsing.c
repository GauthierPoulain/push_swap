/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:05:40 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/24 10:18:06 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	fill_stack_a(t_checker *checker, int argc, char **argv)
{
	int		i;

	checker->stack_a.size = argc - 1;
	checker->stack_a.stack = malloc(sizeof(int) * (argc - 1));
	if (!checker->stack_a.stack)
		close_checker(CLOSE_ERROR);
	checker->stack_a.stack = checker->stack_a.stack;
	i = 1;
	while (i < argc)
	{
		checker->stack_a.stack[i - 1] = ft_atoi(argv[i]);
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
		checker->stack_b.stack[i] = 0;
		i++;
	}
	checker->stack_b.size = -1;
}

void	parsing(t_checker *checker, int argc, char **argv)
{
	parsing_check(argc, argv);
	fill_stack_a(checker, argc, argv);
	fill_stack_b(checker);
}
