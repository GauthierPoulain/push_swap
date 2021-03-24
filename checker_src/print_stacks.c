/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:00:43 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/24 10:11:41 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

void	print_stacks(t_checker *checker)
{
	int		i;

	i = 0;
	printf("|----------------------------------------------------|\n");
	printf("|id    |stack a               |stack b               |\n");
	printf("|      |size : %-15zd|size : %-15zd|\n", checker->stack_a.size,
		checker->stack_b.size);
	printf("|----------------------------------------------------|\n");
	while (i < checker->stack_a.size)
	{
		printf("|%-6d|%-22d|%-22d|\n", i, checker->stack_a.stack[i],
			checker->stack_b.stack[i]);
		i++;
	}
	printf("|----------------------------------------------------|\n");
}
