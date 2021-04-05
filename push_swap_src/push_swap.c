/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:34:32 by gapoulai          #+#    #+#             */
/*   Updated: 2021/04/05 10:14:02 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

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
		sort_under_five(checker);
	else if (checker->stack_a.size <= 240)
		sort_large(checker, 6);
	else
		sort_large(checker, 13);
	if (checker->stack_b.size)
		close_program(CLOSE_ERROR);
	get_algo(checker);
}

int	main(int argc, char **argv)
{
	t_checker	checker;

	parsing(&checker, argc, argv);
	checker.moves = NULL;
	do_move(&checker, "init");
	get_algo(&checker);
	if (!DIRECT_PRINT)
		print_moves(&checker);
	if (PRINT_OP_COUNT)
		do_move(&checker, "print");
	close_program(CLOSE_NOPRINT);
}
