/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 03:14:26 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/24 14:10:31 by gapoulai         ###   ########lyon.fr   */
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
	t_list		*instru;
}				t_checker;

void	close_checker(int code);

void	parsing(t_checker *checker, int argc, char **argv);
void	parsing_check(int argc, char **argv);
void	print_stacks(t_checker *checker);
void	get_instru(t_checker *checker);
void	print_instru(t_checker *checker);

void	rot1(t_stack *stack);
void	rotn1(t_stack *stack);

void	ft_swap(int *a, int *b);

void	swap_a(t_checker *checker);
void	swap_b(t_checker *checker);
void	swap_all(t_checker *checker);

#endif
