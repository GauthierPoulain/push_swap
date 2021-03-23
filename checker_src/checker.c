/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 03:02:14 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/23 16:27:55 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

int	main(int argc, char **argv)
{
	t_checker	checker;

	parsing(&checker, argc, argv);
	close_checker(CLOSE_OK);
}
