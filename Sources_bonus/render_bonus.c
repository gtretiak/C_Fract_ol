/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:18:20 by gtretiak          #+#    #+#             */
/*   Updated: 2025/01/30 12:22:53 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = (img->line_len * y) + (x * (img->bpp / 8));
	*((unsigned int *)(img->pixels + offset)) = color;
}

static void	ft_determine_type(t_complex *z, t_complex *c)
{
	c->x = z->x;
	c->y = z->y;
}

void	ft_handle_pixels(int x, int y, t_mlx *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = ft_scale(x, -2.0, 0.9, WIDTH) * fractol->zoom + fractol->shift_x;
	z.y = ft_scale(y, 1.8, -1.8, HEIGHT) * fractol->zoom + fractol->shift_y;
	ft_determine_type(&z, &c);
	while (i < fractol->iter)
	{
		z = ft_pow_complex(z, fractol->power);
		z = ft_sum_complex(z, c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = ft_scale(i + fractol->color_shift,
					0x000000, 0xffffff, fractol->iter);
			ft_pixel_put(x, y, &fractol->img, color);
			return ;
		}
		i++;
	}
	ft_pixel_put(x, y, &fractol->img, 0xccff00);
}

void	ft_render(t_mlx *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
			ft_handle_pixels(x, y, fractol);
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}
