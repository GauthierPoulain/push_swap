/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:21:42 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/24 14:17:38 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

void	rotn1(t_stack *stack)
{
	int		*st;
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

void	ft_swap(int *a, int *b)
{
	int	salut;

	salut = *a;
	*a = *b;
	*b = salut;
}

int		ft_pop(t_stack *stack)
{
	int		buff;

	rotn1(stack);
	return (buff);
}

void	ft_push(t_stack *stack, int value)
{
	stack->size++;
}
