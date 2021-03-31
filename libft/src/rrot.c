/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:26:53 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/31 15:35:44 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	rotn1(t_stack *stack)
{
	int		*st;
	int		i;
	int		buff;

	if (stack->size < 2)
		return ;
	st = stack->stack;
	buff = st[stack->size];
	i = stack->size;
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
