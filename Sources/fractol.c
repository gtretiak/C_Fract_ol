/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:30:24 by gtretiak          #+#    #+#             */
/*   Updated: 2025/01/30 15:32:30 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set(t_mlx *fractol, char *s)
{
	fractol->name = s;
	fractol->dance = 0;
	ft_putstr_fd(1);
	fractol->golden_ratio = 0;
}

void	ft_set_julia(t_mlx *fractol, char *arg)
{
	if (!ft_strncmp(arg, "Golden_ratio2", 13))
		fractol->golden_ratio = 2;
	else if (!ft_strncmp(arg, "Golden_ratio", 12))
		fractol->golden_ratio = 1;
	else if (!ft_strncmp(arg, "Dance", 5))
		fractol->dance = 1;
	else
	{
		fractol->julia_x = 0;
		fractol->julia_y = ft_atoi_double(arg);
	}
}

void	ft_set_julia_four(t_mlx *fractol, char *arg1, char *arg2)
{
	fractol->julia_x = ft_atoi_double(arg1);
	fractol->julia_y = ft_atoi_double(arg2);
}

int	main(int argc, char **argv)
{
	t_mlx	fractol;

	if ((argc == 2 && !ft_strncmp(argv[1], "Mandelbrot", 10))
		|| ((argc == 4 || argc == 3)
			&& !ft_strncmp(argv[1], "Julia", 5)))
	{
		ft_set(&fractol, argv[1]);
		ft_init(&fractol);
		if (argc == 4 && !ft_strncmp(argv[1], "Julia", 5))
			ft_set_julia_four(&fractol, argv[2], argv[3]);
		else if (argc == 3 && !ft_strncmp(argv[1], "Julia", 5))
			ft_set_julia(&fractol, argv[2]);
		ft_render(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
	{
		ft_putstr_fd(2);
		exit(2);
	}
}
