/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:26:53 by gapoulai          #+#    #+#             */
/*   Updated: 2021/04/02 06:33:40 by gapoulai         ###   ########lyon.fr   */
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

bool	rotate_rra(t_checker *checker)
{
	if (checker->stack_a.size < 2)
		return (false);
	rotn1(&checker->stack_a);
	return (true);
}

bool	rotate_rrb(t_checker *checker)
{
	if (checker->stack_b.size < 2)
		return (false);
	rotn1(&checker->stack_b);
	return (true);
}

bool	rotate_rrr(t_checker *checker)
{
	bool	rra;
	bool	rrb;

	rra = rotate_rra(checker);
	rrb = rotate_rrb(checker);
	return (rra || rrb);
}
