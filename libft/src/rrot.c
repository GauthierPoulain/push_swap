/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:26:53 by gapoulai          #+#    #+#             */
/*   Updated: 2021/04/01 13:18:12 by gapoulai         ###   ########lyon.fr   */
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
	buff = st[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		st[i] = st[i - 1];
		i--;
	}
	st[0] = buff;
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
