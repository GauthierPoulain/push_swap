/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:05:40 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/23 17:12:05 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	fill_stack(t_checker *checker, int argc, char **argv)
{
	int		i;
	int		*stack;

	checker->stack_a.size = argc - 1;
	checker->stack_a.stack = malloc(sizeof(int) * (argc - 1));
	if (!checker->stack_a.stack)
		close_checker(CLOSE_ERROR);
	stack = checker->stack_a.stack;
	i = 1;
	while (i < argc)
	{
		stack[i - 1] = ft_atoi(argv[i]);
		i++;
	}
}

void	parsing(t_checker *checker, int argc, char **argv)
{
	parsing_check(argc, argv);
	fill_stack(checker, argc, argv);
}