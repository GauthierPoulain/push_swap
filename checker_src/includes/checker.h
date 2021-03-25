/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 03:14:26 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/25 12:43:13 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/libft.h"

# define 	PRINT_STACKS	1

# define CLOSE_OK		0
# define CLOSE_KO		1
# define CLOSE_ERROR	2

typedef struct s_stack
{
	int			*stack;
	ssize_t		size;
}				t_stack;

typedef struct s_checker
{
	t_stack		stack_a;
	t_stack		stack_b;
}				t_checker;

void	close_checker(int code);

void	parsing(t_checker *checker, int argc, char **argv);
void	parsing_check(int argc, char **argv);
void	print_stacks(t_checker *checker);
void	get_instru(t_checker *checker);
void	run_instru(t_checker *checker, char *instr);

void	ft_swap(int *a, int *b);

void	swap_sa(t_checker *checker);
void	swap_sb(t_checker *checker);
void	swap_ss(t_checker *checker);

void	ft_push(t_stack *dst, t_stack *src);

void	push_pa(t_checker *checker);
void	push_pb(t_checker *checker);

void	rot1(t_stack *stack);

void	rotate_ra(t_checker *checker);
void	rotate_rb(t_checker *checker);
void	rotate_rr(t_checker *checker);

void	rotn1(t_stack *stack);

void	rotate_rra(t_checker *checker);
void	rotate_rrb(t_checker *checker);
void	rotate_rrr(t_checker *checker);

void	ft_swap(int *a, int *b);

void	swap_sa(t_checker *checker);
void	swap_sb(t_checker *checker);
void	swap_ss(t_checker *checker);

#endif
