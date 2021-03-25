/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 03:02:14 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/25 12:54:39 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

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
	print_stacks(&checker);
	get_instru(&checker);
	if (is_sorted(&checker))
		close_checker(CLOSE_OK);
	close_checker(CLOSE_KO);
}
