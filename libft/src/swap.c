/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:18:31 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/30 13:32:48 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_swap(int *a, int *b)
{
	int	salut;

	salut = *a;
	*a = *b;
	*b = salut;
}

void	swap_sa(t_checker *checker)
{
	if (checker->stack_a.size > 1)
		ft_swap(&checker->stack_a.stack[0], &checker->stack_a.stack[1]);
}

void	swap_sb(t_checker *checker)
{
	if (checker->stack_b.size > 1)
		ft_swap(&checker->stack_b.stack[0], &checker->stack_b.stack[1]);
}

void	swap_ss(t_checker *checker)
{
	swap_sa(checker);
	swap_sb(checker);
}
