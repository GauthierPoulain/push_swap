/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:24:58 by gapoulai          #+#    #+#             */
/*   Updated: 2021/04/02 06:33:03 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	rot1(t_stack *stack)
{
	int		*st;
	int		i;
	int		buff;

	if (stack->size < 2)
		return ;
	st = stack->stack;
	buff = st[0];
	i = 1;
	while (i < stack->size)
	{
		st[i - 1] = st[i];
		i++;
	}
	st[stack->size - 1] = buff;
}

bool	rotate_ra(t_checker *checker)
{
	if (checker->stack_a.size < 2)
		return (false);
	rot1(&checker->stack_a);
	return (true);
}

bool	rotate_rb(t_checker *checker)
{
	if (checker->stack_b.size < 2)
		return (false);
	rot1(&checker->stack_b);
	return (true);
}

bool	rotate_rr(t_checker *checker)
{
	bool	ra;
	bool	rb;

	ra = rotate_ra(checker);
	rb = rotate_rb(checker);
	return (ra || rb);
}
