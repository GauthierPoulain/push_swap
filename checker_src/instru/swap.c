/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:18:31 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/24 14:11:11 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	swap_a(t_checker *checker)
{
	if (checker->stack_a.size > 1)
		ft_swap(&checker->stack_a.stack[0], &checker->stack_a.stack[1]);
}

void	swap_b(t_checker *checker)
{
	if (checker->stack_b.size > 1)
		ft_swap(&checker->stack_b.stack[0], &checker->stack_b.stack[1]);
}

void	swap_all(t_checker *checker)
{
	swap_a(checker);
	swap_b(checker);
}
