/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_p2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:35:55 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/23 17:20:21 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

bool	ft_ischarset(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

bool	ft_isinrange(long long value, long long min, long long max)
{
	return (value >= min && value <= max);
}
