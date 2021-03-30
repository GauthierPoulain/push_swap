/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:52:26 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/30 16:43:03 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	is_sorted(t_stack stack)
{
	int		i;

	i = -1;
	while (++i < stack.size - 1)
		if (stack.stack[i] >= stack.stack[i + 1])
			return (false);
	return (true);
}
