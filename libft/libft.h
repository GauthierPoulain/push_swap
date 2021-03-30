/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:31:41 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/30 13:21:24 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_stack
{
	int				*stack;
	ssize_t			size;
}				t_stack;

typedef struct s_checker
{
	t_stack			stack_a;
	t_stack			stack_b;
}				t_checker;

int			ft_atoi(const char *str);
bool		ft_isalpha(char c);
bool		ft_isdigit(char c);
bool		ft_isalnum(char c);
bool		ft_isascii(char c);
bool		ft_isprint(char c);
bool		ft_isspace(char c);
bool		ft_ischarset(char c, char *charset);
bool		ft_isinrange(long long value, long long min, long long max);
size_t		ft_strlen(char *s);
void		ft_print_err(char *msg);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstadd_front(t_list **alst, t_list *new);
t_list		*ft_lstnew(void *content);
int			ft_get_next_line(int fd, char **line);
char		*ft_strdup(char *s1);
bool		ft_strcmp(const char *s1, const char *s2);

void		ft_swap(int *a, int *b);

void		swap_sa(t_checker *checker);
void		swap_sb(t_checker *checker);
void		swap_ss(t_checker *checker);

void		ft_push(t_stack *dst, t_stack *src);

void		push_pa(t_checker *checker);
void		push_pb(t_checker *checker);

void		rot1(t_stack *stack);

void		rotate_ra(t_checker *checker);
void		rotate_rb(t_checker *checker);
void		rotate_rr(t_checker *checker);

void		rotn1(t_stack *stack);

void		rotate_rra(t_checker *checker);
void		rotate_rrb(t_checker *checker);
void		rotate_rrr(t_checker *checker);

void		ft_swap(int *a, int *b);

void		swap_sa(t_checker *checker);
void		swap_sb(t_checker *checker);
void		swap_ss(t_checker *checker);

#endif
