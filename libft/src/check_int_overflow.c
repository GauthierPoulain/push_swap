/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int_overflow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:12:26 by gapoulai          #+#    #+#             */
/*   Updated: 2021/04/05 10:27:29 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	int		i;

	str = malloc(size * count);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < (int)count)
		str[i] = 0;
	return (str);
}

static int	ft_itoa_getsize(int n)
{
	int		count;

	count = 0;
	if (n < 0)
		n *= -1;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			count;
	int			i;
	long int	tmp;

	tmp = n;
	count = ft_itoa_getsize(n);
	if (tmp < 0 || count == 0)
		count++;
	res = ft_calloc(count + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	if (tmp < 0)
	{
		tmp *= -1;
		res[i++] = '-';
	}
	while (count > i)
	{
		res[--count] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (res);
}

bool	check_int_overflow(char *str)
{
	char	*tmp;
	bool	res;

	tmp = ft_itoa(ft_atoi(str));
	if (*str == '-')
	{
		str++;
		while (*str == '0' && ft_strlen(str) > 1)
			str++;
		str--;
		*str = '-';
	}
	else
		while (*str == '0' && ft_strlen(str) > 1)
			str++;
	res = ft_strcmp(str, tmp);
	free(tmp);
	return (!res);
}
