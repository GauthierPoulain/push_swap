/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:05:40 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/25 14:21:40 by gapoulai         ###   ########lyon.fr   */
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

static bool	check_atoi(char *str)
{
	bool	res;
	bool	sign;

	sign = false;
	res = false;
	while (*str)
	{
		if (ft_isdigit(*str))
			res = true;
		else
		{
			if (sign)
				return (false);
			sign = true;
		}
		if (res)
			if (!ft_isdigit(*str))
				return (false);
		str++;
	}
	return (res);
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
		if (!check_atoi(argv[i]))
			close_checker(CLOSE_ERROR);
		checker->stack_a.stack[i - 1] = ft_atoi(argv[i]);
		if (exist(checker->stack_a, checker->stack_a.stack[i - 1]))
			close_checker(CLOSE_ERROR);
		checker->stack_a.size = i++;
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
	checker->stack_b.size = 0;
}

void	parsing(t_checker *checker, int argc, char **argv)
{
	parsing_check(argc, argv);
	fill_stack_a(checker, argc, argv);
	fill_stack_b(checker);
}
