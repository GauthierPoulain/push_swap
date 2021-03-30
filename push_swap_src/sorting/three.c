/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:23:01 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/30 16:37:34 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_checker *checker)
{	
	if (checker->stack_a.stack[0] > checker->stack_a.stack[1])
	{
		if (checker->stack_a.stack[0] > checker->stack_a.stack[2])
			do_move(checker, "ra");
		else
			do_move(checker, "sa");
	}
	else if (checker->stack_a.stack[1] > checker->stack_a.stack[2])
		do_move(checker, "rra");
}
