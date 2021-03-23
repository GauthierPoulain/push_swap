/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:31:41 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/23 13:40:47 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>

int			ft_atoi(const char *str);
bool		ft_isalpha(char c);
bool		ft_isdigit(char c);
bool		ft_isalnum(char c);
bool		ft_isascii(char c);
bool		ft_isprint(char c);
bool		ft_isspace(char c);
bool		ft_ischarset(char c, char *charset);
bool		ft_isinrange(long long value, long long min, long long max);

#endif
