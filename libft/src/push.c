/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:21:15 by gapoulai          #+#    #+#             */
/*   Updated: 2021/04/02 03:55:05 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_push(t_stack *src, t_stack *dst)
{
	int		buff;

	if (src->size < 1)
		return ;
	buff = src->stack[0];
	dst->size++;
	rot1(src);
	rotn1(dst);
	src->size--;
	dst->stack[0] = buff;
}

bool	push_pa(t_checker *checker)
{
	if (checker->stack_b.size < 1)
		return (false);
	ft_push(&checker->stack_b, &checker->stack_a);
	return (true);
}

bool	push_pb(t_checker *checker)
{
	if (checker->stack_a.size < 1)
		return (false);
	ft_push(&checker->stack_a, &checker->stack_b);
	return (true);
}
