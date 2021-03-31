/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:53:59 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/31 15:54:26 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	close_program(int code)
{
	if (code == CLOSE_ERROR)
	{
		ft_putstr_fd(2, "Error\n");
		exit(EXIT_FAILURE);
	}
	else if (code == CLOSE_OK)
	{
		ft_putstr_fd(1, "OK\n");
		exit(EXIT_SUCCESS);
	}
	else if (code == CLOSE_KO)
	{
		ft_putstr_fd(1, "KO\n");
		exit(EXIT_SUCCESS);
	}
	else if (code == CLOSE_NOPRINT)
		exit(EXIT_SUCCESS);
	ft_putstr_fd(2, "unhandled exit code\n");
	exit(EXIT_FAILURE);
}
