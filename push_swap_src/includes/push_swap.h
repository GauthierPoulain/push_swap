/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:31:59 by gapoulai          #+#    #+#             */
/*   Updated: 2021/04/02 10:24:21 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/libft.h"

# define	DIRECT_PRINT	0
# define	PRINT_OP_COUNT	0

#	define	UNDER_H_SPLIT	6
#	define	OVER_H_SPLIT	13

void	parsing(t_checker *checker, int argc, char **argv);
void	parsing_check(int argc, char **argv);
void	close_push_swap(int code);
void	do_move(t_checker *checker, char *move);
void	count_op(t_checker *checker, char *move);

void	sort_int_tab(int *tab, int size);
int		get_min(t_stack stack);
int		get_max(t_stack stack);
int		get_closer(t_stack stack, int value);

bool	have_higher(t_stack stack, int min);
bool	have_lower(t_stack stack, int max);
bool	have_inrange(t_stack stack, int min, int max);
bool	have_outrange(t_stack stack, int min, int max);

int		get_srt_index(t_stack stack, int pos);

void	sort_two(t_checker *checker);
void	sort_three(t_checker *checker);
void	sort_under_five(t_checker *checker);
void	sort_under_hundred(t_checker *checker);
void	sort_over_hundred(t_checker *checker);

#endif
