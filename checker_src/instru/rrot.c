/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:26:53 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/25 12:27:40 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	rotn1(t_stack *stack)
{
	int *st;
	int		i;
	int		buff;

	st = stack->stack;
	i = stack->size;
	buff = st[stack->size];
	while (i > 0)
	{
		st[i] = st[i - 1];
		i--;
	}
	st[0] = st[stack->size];
}

void	rotate_rra(t_checker *checker)
{
	rotn1(&checker->stack_a);
}

void	rotate_rrb(t_checker *checker)
{
	rotn1(&checker->stack_b);
}

void	rotate_rrr(t_checker *checker)
{
	rotn1(&checker->stack_a);
	rotn1(&checker->stack_b);
}
