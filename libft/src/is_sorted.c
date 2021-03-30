/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:52:26 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/30 14:52:45 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	is_sorted(t_checker *checker)
{
	int		i;

	i = -1;
	while (++i < checker->stack_a.size - 1)
		if (checker->stack_a.stack[i] >= checker->stack_a.stack[i + 1])
			return (false);
	return (true);
}
