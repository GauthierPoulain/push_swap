/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:27:19 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/23 13:47:43 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_atoi_calcsign(int pos, int neg)
{
	if ((!pos && !neg) || (pos == 1 && !neg))
		return (1);
	else if (!pos && neg == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	char	*tstr;
	int		pos;
	int		neg;
	int		res;

	tstr = (char *)str;
	pos = 0;
	neg = 0;
	while (ft_isspace(*tstr))
		tstr++;
	while (*tstr == '+' || *tstr == '-')
	{
		if (*tstr++ == '+')
			pos++;
		else
			neg++;
	}
	res = 0;
	while (ft_isdigit(*tstr))
	{
		res *= 10;
		res += *tstr - '0';
		tstr++;
	}
	return (res * ft_atoi_calcsign(pos, neg));
}
