/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:34:03 by gtretiak          #+#    #+#             */
/*   Updated: 2025/01/30 12:23:55 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_close(t_mlx *fractol)
{
	ft_putstr_fd("Closing...\n", 1);
	mlx_destroy_image(fractol->mlx, fractol->img.img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	exit (0);
}

int	ft_handle_mouse(int button, int x, int y, t_mlx *fractol)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = ft_scale(x, -2.0, 0.9, WIDTH);
	mouse_y = ft_scale(y, 1.8, -1.8, HEIGHT);
	if (button == 5)
	{
		fractol->shift_x += (mouse_x - fractol->shift_x) * 0.1;
		fractol->shift_y += (mouse_y - fractol->shift_y) * 0.1;
		fractol->zoom *= 1.1;
	}
	else if (button == 4)
	{
		fractol->shift_x += (mouse_x - fractol->shift_x) * 0.1;
		fractol->shift_y += (mouse_y - fractol->shift_y) * 0.1;
		fractol->zoom *= 0.9;
	}
	ft_render(fractol);
	return (0);
}

int	ft_handle_key(int keysym, t_mlx *fractol)
{
	if (keysym == XK_Escape || keysym == XK_q || keysym == XK_x)
		ft_close(fractol);
	else if (keysym == XK_Left)
		fractol->shift_x -= (0.5 * fractol->zoom);
	else if (keysym == XK_Right)
		fractol->shift_x += (0.5 * fractol->zoom);
	else if (keysym == XK_Up)
		fractol->shift_y += (0.5 * fractol->zoom);
	else if (keysym == XK_Down)
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if (keysym == XK_KP_Add || keysym == XK_plus || keysym == XK_equal)
		fractol->iter += 10;
	else if (keysym == XK_KP_Subtract || keysym == XK_minus)
		fractol->iter -= 10;
	else if (keysym == XK_c)
		fractol->color_shift += 10;
	else if (keysym == XK_p)
	{
		if (fractol->power < 8)
			fractol->power += 1;
		else
			fractol->power = 2;
	}
	ft_render(fractol);
	return (0);
}
