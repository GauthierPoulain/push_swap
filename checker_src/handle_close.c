/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 03:24:46 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/18 04:13:01 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

void	close_checker(int code)
{
	if (code == CLOSE_ERROR)
	{
		printf("Error\n");
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
