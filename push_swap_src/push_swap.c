/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:34:32 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/30 15:01:42 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	close_checker(int code)
{
	if (code == CLOSE_ERROR)
	{
		ft_print_err("Error\n");
		exit(EXIT_FAILURE);
	}
	else if (code == CLOSE_OK)
	{
		printf("OK\n");
		exit(EXIT_SUCCESS);
	}
	else if (code == CLOSE_KO)
	{
		printf("KO\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("unhandled close code\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_checker	checker;

	parsing(&checker, argc, argv);
	printf("salut\n");
	return (0);
}
