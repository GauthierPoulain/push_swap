/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:24:58 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/31 15:35:55 by gapoulai         ###   ########lyon.fr   */
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
