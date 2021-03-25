/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:21:15 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/25 12:39:32 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_push(t_stack *src, t_stack *dst)
{
	int		buff;

	if (src->size < 1)
		return ;
	buff = src->stack[0];
	src->stack[0] = 0;
	rot1(src);
	rotn1(dst);
	src->size--;
	dst->size++;
	dst->stack[0] = buff;
}

void	push_pa(t_checker *checker)
{
	ft_push(&checker->stack_b, &checker->stack_a);
}

void	push_pb(t_checker *checker)
{
	ft_push(&checker->stack_a, &checker->stack_b);
}
