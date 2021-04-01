/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:34:32 by gapoulai          #+#    #+#             */
/*   Updated: 2021/04/01 13:47:38 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	do_move(t_checker *checker, char *move)
{
	if (!ft_strcmp("sa", move))
		swap_sa(checker);
	else if (!ft_strcmp("sb", move))
		swap_sb(checker);
	else if (!ft_strcmp("ss", move))
		swap_ss(checker);
	else if (!ft_strcmp("pa", move))
		push_pa(checker);
	else if (!ft_strcmp("pb", move))
		push_pb(checker);
	else if (!ft_strcmp("ra", move))
		rotate_ra(checker);
	else if (!ft_strcmp("rb", move))
		rotate_rb(checker);
	else if (!ft_strcmp("rr", move))
		rotate_rr(checker);
	else if (!ft_strcmp("rra", move))
		rotate_rra(checker);
	else if (!ft_strcmp("rrb", move))
		rotate_rrb(checker);
	else if (!ft_strcmp("rrr", move))
		rotate_rrr(checker);
	else
		close_program(CLOSE_ERROR);
	ft_lstadd_back(&checker->moves, ft_lstnew(ft_strdup(move)));
	// ft_putendl_fd(1, move);
}

void	foretdeif(t_list *lst, bool *skip)
{
	*skip = true;
	if ((!ft_strcmp(lst->content, "ra")
			&& !ft_strcmp(lst->next->content, "rb"))
		|| (!ft_strcmp(lst->content, "rb")
			&& !ft_strcmp(lst->next->content, "ra")))
		ft_putendl_fd(1, "rr");
	else if ((!ft_strcmp(lst->content, "rra")
			&& !ft_strcmp(lst->next->content, "rrb"))
		|| (!ft_strcmp(lst->content, "rrb")
			&& !ft_strcmp(lst->next->content, "rra")))
		ft_putendl_fd(1, "rrr");
	else if ((!ft_strcmp(lst->content, "sa")
			&& !ft_strcmp(lst->next->content, "sb"))
		|| (!ft_strcmp(lst->content, "sb")
			&& !ft_strcmp(lst->next->content, "sa")))
		ft_putendl_fd(1, "ss");
	else
		*skip = false;
}

void	print_moves(t_checker *checker)
{
	t_list	*lst;
	bool	skip;

	lst = checker->moves;
	while (lst)
	{
		skip = false;
		if (lst->next)
			foretdeif(lst, &skip);
		if (skip)
			lst = lst->next;
		else
			ft_putendl_fd(1, lst->content);
		lst = lst->next;
	}
}

void	get_algo(t_checker *checker)
{
	if (is_sorted(checker->stack_a))
		return ;
	if (checker->stack_a.size == 2)
		sort_two(checker);
	else if (checker->stack_a.size == 3)
		sort_three(checker);
	else if (checker->stack_a.size <= 5)
		sort_four_five(checker);
	else if (checker->stack_a.size <= 100)
		sort_six_to_hundred(checker);
	else
		close_program(CLOSE_ERROR);
	if (checker->stack_b.size)
		close_program(CLOSE_ERROR);
	get_algo(checker);
}

int	main(int argc, char **argv)
{
	t_checker	checker;

	parsing(&checker, argc, argv);
	checker.moves = NULL;
	get_algo(&checker);
	print_moves(&checker);
	close_program(CLOSE_NOPRINT);
}
