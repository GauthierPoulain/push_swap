/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:24:58 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/30 13:32:42 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	rot1(t_stack *stack)
{
	int		*st;
	int		i;

	st = stack->stack;
	i = 0;
	st[stack->size] = st[i];
	while (i < stack->size)
	{
		st[i] = st[i + 1];
		i++;
	}
}

void	rotate_ra(t_checker *checker)
{
	rot1(&checker->stack_a);
}

void	rotate_rb(t_checker *checker)
{
	rot1(&checker->stack_b);
}

void	rotate_rr(t_checker *checker)
{
	rot1(&checker->stack_a);
	rot1(&checker->stack_b);
}
