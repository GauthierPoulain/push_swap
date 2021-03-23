/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:00:43 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/23 17:16:57 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

void	print_stacks(t_checker *checker)
{
	int		i;

	i = 0;
	printf("|-------------------------------------------------------|\n");
	printf("|stack a                    |stack b                    |\n");
	printf("|size : %-20zd|size : %-20zd|\n", checker->stack_a.size,
			checker->stack_b.size);
	printf("|-------------------------------------------------------|\n");
	while (i < checker->stack_a.size)
	{
		printf("|%-27d|%-27d|\n", checker->stack_a.stack[i],
				checker->stack_a.stack[i]);
		i++;
	}
	printf("|-------------------------------------------------------|\n");
}