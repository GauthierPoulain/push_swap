/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:03:49 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/23 16:32:08 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/checker.h"

static bool	check_arg(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
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
