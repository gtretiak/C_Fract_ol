/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:00:17 by gtretiak          #+#    #+#             */
/*   Updated: 2025/01/27 17:26:07 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (n >= 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (*s1 == '\0')
			return (0);
		++s1;
		++s2;
		--n;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	while (*s)
		write(fd, s++, 1);
}

static int	ft_sign(char sign)
{
	if (sign == 45)
		return (-1);
	else
		return (0);
}

static long	ft_get_int(char **str)
{
	long	i;

	i = 0;
	while (**str != '.' && **str)
	{
		i *= 10;
		i = i + (**str - '0');
		(*str)++;
	}
	return (i);
}

double	ft_atoi_double(char *str)
{
	long	i;
	double	f;
	double	after_dot;
	short	s;

	i = 0;
	f = 0;
	s = 1;
	after_dot = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		++str;
	if (*str == 43 || *str == 45)
	{
		s = ft_sign(*str);
		++str;
	}
	i = ft_get_int(&str);
	if (*str == '.')
		++str;
	while (*str)
	{
		after_dot /= 10;
		f = f + (*str++ - '0') * after_dot;
	}
	return ((i + f) * s);
}
