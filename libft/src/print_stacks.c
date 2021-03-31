/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:50:42 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/31 13:32:24 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	print_stacks_loop(t_checker *checker, int i, int max)
{
	while (++i < max)
	{
		printf("|%-6d", i);
		if (i < checker->stack_a.size)
			printf("|%-22d", checker->stack_a.stack[i]);
		else
			printf("|%-22s", "");
		if (i < checker->stack_b.size)
			printf("|%-22d", checker->stack_b.stack[i]);
		else
			printf("|%-22s", "");
		printf("|\n");
	}
}

void	print_stacks(t_checker *checker)
{
	int		max;

	if (checker->stack_a.size < checker->stack_b.size)
		max = checker->stack_b.size;
	else
		max = checker->stack_a.size;
	printf("------------------------------------------------------\n");
	printf("|id    |stack a               |stack b               |\n");
	printf("|      |size : %-15zd|size : %-15zd|\n", checker->stack_a.size,
		checker->stack_b.size);
	printf("------------------------------------------------------\n");
	print_stacks_loop(checker, -1, max);
	printf("------------------------------------------------------\n");
}
