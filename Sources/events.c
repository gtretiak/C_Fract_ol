/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:34:03 by gtretiak          #+#    #+#             */
/*   Updated: 2025/01/30 13:09:23 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_mlx *fractol)
{
	ft_putstr_fd(3);
	mlx_destroy_image(fractol->mlx, fractol->img.img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	exit (0);
}

int	ft_handle_mouse(int button, int x, int y, t_mlx *fractol)
{
	int	x_init;
	int	y_init;

	x_init = x;
	y_init = y;
	if (button == 5)
		fractol->zoom *= 1.1;
	else if (button == 4)
		fractol->zoom *= 0.9;
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
	ft_render(fractol);
	return (0);
}
