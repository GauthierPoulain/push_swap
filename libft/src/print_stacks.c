/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:50:42 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/31 11:07:41 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
		printf("|%-6d", i);
		if (i < checker->stack_a.size)
			printf("|%-22d", checker->stack_a.stack[i]);
		else
			printf("|%-22c", ' ');
		if (i < checker->stack_b.size)
			printf("|%-22d", checker->stack_b.stack[i]);
		else
			printf("|%-22c", ' ');
		printf("|\n");
		i++;
	}
	printf("|----------------------------------------------------|\n");
}
