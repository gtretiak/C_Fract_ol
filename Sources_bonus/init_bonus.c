/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:56:50 by gtretiak          #+#    #+#             */
/*   Updated: 2025/01/30 12:29:43 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	ft_malloc_error(void)
{
	perror("Problems with malloc");
	exit (2);
}

void	ft_settings(t_mlx *fractol)
{
	fractol->escape_value = 4;
	fractol->iter = 2; // initial detail level
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0; // no zoom
	fractol->color_shift = 1;
	fractol->power = 2; // initial power = 2
}

void	ft_events(t_mlx *fractol)
{
	mlx_hook(fractol->win, KeyPress, KeyPressMask, ft_handle_key, fractol); // hooks keyboard events
	mlx_mouse_hook(fractol->win, ft_handle_mouse, fractol); // hooks mouse events
	mlx_hook(
		fractol->win, DestroyNotify, StructureNotifyMask, ft_close, fractol); // triggers on closing the window
}

void	ft_init(t_mlx *fractol)
{
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
		ft_malloc_error();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, fractol->name);
	if (fractol->win == NULL)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		ft_malloc_error();
	}
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (fractol->img.img == NULL)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		ft_malloc_error();
	}
	fractol->img.pixels = mlx_get_data_addr(fractol->img.img, // used to draw directly to the image buffer
			&fractol->img.bpp,
			&fractol->img.line_len,
			&fractol->img.endian);
	ft_events(fractol); // set up input events
	ft_settings(fractol); // apply default parameters
}
