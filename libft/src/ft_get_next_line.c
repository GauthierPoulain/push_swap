/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:13:36 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/24 10:41:24 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_strjoinc(char *s1, char c)
{
	int		i;
	int		tlen;
	char	*res;

	if (!s1)
	{
		res = malloc(sizeof(char) * 2);
		if (!res)
			return (NULL);
		res[0] = c;
		res[1] = 0;
		return (res);
	}
	tlen = ft_strlen(s1) + 2;
	res = malloc(sizeof(char) * tlen);
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	res[i] = c;
	res[i + 1] = 0;
	free(s1);
	return (res);
}

static bool	custom_read(int fd, char *buffer, int *readvalue)
{
	*readvalue = read(fd, buffer, 1);
	return (*readvalue != 0);
}

int	ft_get_next_line(int fd, char **line)
{
	char	buffer;
	int		ret;
	int		readvalue;

	ret = 0;
	if (!line)
		return (-1);
	*line = malloc(sizeof(char) * 1);
	if (!*line)
		return (-1);
	*line[0] = 0;
	while (custom_read(fd, &buffer, &readvalue) && buffer != '\n')
		*line = ft_strjoinc(*line, buffer);
	if (!*line)
		*line = ft_strjoinc(*line, '\0');
	if (readvalue > 0)
		ret = 1;
	return (ret);
}
