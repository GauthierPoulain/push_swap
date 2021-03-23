/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 03:14:26 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/23 16:09:17 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/libft.h"

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

#endif
