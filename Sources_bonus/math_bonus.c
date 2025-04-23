/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:29:41 by gtretiak          #+#    #+#             */
/*   Updated: 2025/01/30 12:31:34 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	ft_scale(double num, double new_min, double new_max, double old_max)
{
	return ((num - 0) / (old_max - 0) * (new_max - new_min) + new_min);
}

t_complex	ft_sum_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_complex	ft_square_complex(t_complex z)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}

t_complex	ft_pow_complex(t_complex z, int power)
{
	int			i;
	t_complex	res;

	i = 0;
	res = z;
	while (i++ < power)
		res = ft_sum_complex(ft_square_complex(res), res);
	return (res);
}
