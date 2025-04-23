/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:18:20 by gtretiak          #+#    #+#             */
/*   Updated: 2025/02/02 15:48:53 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = (img->line_len * y) + (x * (img->bpp / 8));
	*((unsigned int *)(img->pixels + offset)) = color;
}

static void	ft_determine_z(int *x, int *y, t_complex *z, t_mlx *fractol)
{
	if (!ft_strncmp(fractol->name, "Julia", 5))
	{
		z->x = ft_scale(*x, -2.0, 2.0, WIDTH)
			* fractol->zoom + fractol->shift_x;
		z->y = ft_scale(*y, 2.0, -2.0, HEIGHT)
			* fractol->zoom + fractol->shift_y;
	}
	else
	{
		z->x = ft_scale(*x, -2.0, 1.0, WIDTH)
			* fractol->zoom + fractol->shift_x;
		z->y = ft_scale(*y, 1.5, -1.5, HEIGHT)
			* fractol->zoom + fractol->shift_y;
	}
}

static void	ft_determine_c(t_complex *z, t_complex *c, t_mlx *fractol)
{
	if (!ft_strncmp(fractol->name, "Julia", 5))
	{
		if (fractol->golden_ratio == 1)
		{
			c->x = 1 - ((1 + sqrt(5)) / 2);
			c->y = 0;
		}
		else if (fractol->golden_ratio == 2)
		{
			c->x = ((1 + sqrt(5)) / 2) - 2;
			c->y = ((1 + sqrt(5)) / 2) - 1;
		}
		else
		{
			c->x = fractol->julia_x;
			c->y = fractol->julia_y;
		}
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	ft_handle_pixels(int x, int y, t_mlx *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	ft_determine_z(&x, &y, &z, fractol);
	ft_determine_c(&z, &c, fractol);
	while (i < fractol->iter)
	{
		z = ft_sum_complex(ft_square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = ft_scale(i, 0x000000, 0xffffff, fractol->iter);
			ft_pixel_put(x, y, &fractol->img, color);
			return ;
		}
		i++;
	}
	ft_pixel_put(x, y, &fractol->img, 0xccff00);
}

void	ft_render(t_mlx *fractol)
{
	double	a;
	int		x;
	int		y;

	if (fractol->dance == 1)
	{
		fractol->dance = 0;
		a = 0;
		while (a <= 2 * M_PI)
		{
			fractol->julia_x = 0.7885 * cos(a);
			fractol->julia_y = 0.7885 * sin(a);
			ft_render(fractol);
			a += 0.1;
		}
	}
	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
			ft_handle_pixels(x, y, fractol);
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}
