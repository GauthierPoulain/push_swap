/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 01:54:59 by gapoulai          #+#    #+#             */
/*   Updated: 2021/04/02 04:04:14 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	print_count(t_checker *checker)
{
	printf("sa = %d\nsb = %d\nss = %d\n", checker->count.sa,
		checker->count.sb, checker->count.ss);
	printf("pa = %d\npb = %d\n", checker->count.pa, checker->count.pb);
	printf("ra = %d\nrb = %d\nrr = %d\n", checker->count.ra,
		checker->count.rb, checker->count.rr);
	printf("rra = %d\nrrb = %d\nrrr = %d\n", checker->count.rra,
		checker->count.rrb, checker->count.rrr);
}

void	count_op(t_checker *checker, char *move)
{
	if (!ft_strcmp("sa", move))
		checker->count.sa++;
	else if (!ft_strcmp("sb", move))
		checker->count.sb++;
	else if (!ft_strcmp("ss", move))
		checker->count.ss++;
	else if (!ft_strcmp("pa", move))
		checker->count.pa++;
	else if (!ft_strcmp("pb", move))
		checker->count.pb++;
	else if (!ft_strcmp("ra", move))
		checker->count.ra++;
	else if (!ft_strcmp("rb", move))
		checker->count.rb++;
	else if (!ft_strcmp("rr", move))
		checker->count.rr++;
	else if (!ft_strcmp("rra", move))
		checker->count.rra++;
	else if (!ft_strcmp("rrb", move))
		checker->count.rrb++;
	else if (!ft_strcmp("rrr", move))
		checker->count.rrr++;
}

void	init_op(t_checker *checker)
{
	checker->count.sa = 0;
	checker->count.sb = 0;
	checker->count.ss = 0;
	checker->count.pa = 0;
	checker->count.pb = 0;
	checker->count.ra = 0;
	checker->count.rb = 0;
	checker->count.rr = 0;
	checker->count.rra = 0;
	checker->count.rrb = 0;
	checker->count.rrr = 0;
}

static void	do_move_2(t_checker *checker, char *move, bool *save)
{
	if (!ft_strcmp("ra", move) && !rotate_ra(checker))
		*save = false;
	else if (!ft_strcmp("rb", move) && !rotate_rb(checker))
		*save = false;
	else if (!ft_strcmp("rr", move) && !rotate_rr(checker))
		*save = false;
	else if (!ft_strcmp("rra", move) && !rotate_rra(checker))
		*save = false;
	else if (!ft_strcmp("rrb", move) && !rotate_rrb(checker))
		*save = false;
	else if (!ft_strcmp("rrr", move) && !rotate_rrr(checker))
		*save = false;
	else if (!ft_strcmp("print", move))
	{
		*save = false;
		print_count(checker);
	}
	else if (!ft_strcmp("init", move))
	{
		*save = false;
		init_op(checker);
	}
}

void	do_move(t_checker *checker, char *move)
{
	bool	save;

	save = true;
	if (!ft_strcmp("sa", move) && !swap_sa(checker))
		save = false;
	else if (!ft_strcmp("sb", move) && !swap_sb(checker))
		save = false;
	else if (!ft_strcmp("ss", move) && !swap_ss(checker))
		save = false;
	else if (!ft_strcmp("pa", move) && !push_pa(checker))
		save = false;
	else if (!ft_strcmp("pb", move) && !push_pb(checker))
		save = false;
	else
		do_move_2(checker, move, &save);
	if (save)
	{
		if (DIRECT_PRINT)
			ft_putendl_fd(1, move);
		else
			ft_lstadd_back(&checker->moves, ft_lstnew(ft_strdup(move)));
		count_op(checker, move);
	}
}
