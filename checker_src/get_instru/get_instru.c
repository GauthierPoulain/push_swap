/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:44:23 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/24 10:54:35 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	get_instru(t_checker *checker)
{
	char	**line;
	int		ret;

	line = malloc(sizeof(char *));
	checker->instru = NULL;
	ret = 1;
	while (ret > 0)
	{
		ret = ft_get_next_line(0, line);
		if (ret == -1)
			close_checker(CLOSE_ERROR);
		ft_lstadd_back(&checker->instru, ft_lstnew(ft_strdup(*line)));
		free(*line);
	}
}
