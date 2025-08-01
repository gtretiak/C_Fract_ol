/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:00:17 by gtretiak          #+#    #+#             */
/*   Updated: 2025/01/30 13:06:55 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (n)
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

void	ft_putstr_fd(int marker)
{
	char	*init;
	char	*error;
	char	*close;
	char	*s;

	init = "Fractol set has been called\n";
	error = "Invalid argument(s). Insert:\n"
		"1) \"<Program name> <Mandelbrot>\";\n"
		"2) \"<Program name> <Julia> <X coordinate> <Y coordinate>\";\n"
		"3) \"<Program name> <Julia> <Y coordinate>\";\n"
		"4) \"<Program name> <Julia> <Golden_ratio>\";\n"
		"5) \"<Program name> <Julia> <Golden_ratio2>\";\n"
		"6) \"<Program name> <Julia> <Dance>\";\n";
	close = "Closing...\n";
	if (marker == 1)
		s = init;
	else if (marker == 2)
		s = error;
	else
		s = close;
	while (*s)
		write(1, s++, 1);
}

static int	ft_sign(char sign)
{
	if (sign == 45) // ASCII for "-"
		return (-1);
	else
		return (0);
}

static long	ft_get_int(char **str)
{
	long	i;

	i = 0;
	while (**str != '.' && **str) // as long as current char is not "." and not the NULL terminator we continue
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
