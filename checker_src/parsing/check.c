/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:03:49 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/30 13:26:05 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	get_instru(t_checker *checker)
{
	char	**line;
	int		ret;

	line = malloc(sizeof(char *));
	ret = 1;
	while (ret > 0)
	{
		ret = ft_get_next_line(0, line);
		if (ret == -1)
			close_checker(CLOSE_ERROR);
		else if (ret == 1)
		{
			run_instru(checker, *line);
			if (PRINT_STACKS)
				print_stacks(checker);
		}
		free(*line);
	}
	free(line);
}

static bool	check_arg(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s) && *s != '-' && *s != '+')
			return (false);
		s++;
	}
	return (true);
}

void	parsing_check(int argc, char **argv)
{
	int		i;

	if (argc < 2)
		close_checker(CLOSE_ERROR);
	i = 1;
	while (i < argc)
	{
		if (!check_arg(argv[i]))
			close_checker(CLOSE_ERROR);
		i++;
	}
}
