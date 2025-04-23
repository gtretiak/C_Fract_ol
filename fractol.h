/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:47:34 by gtretiak          #+#    #+#             */
/*   Updated: 2025/01/30 13:40:56 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"

# ifndef HEIGHT
#  define HEIGHT 800
# endif

# ifndef WIDTH
#  define WIDTH 800
# endif

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img;
	char	*pixels;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
	char	*name;
	double	escape_value;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		iter;
	int		dance;
	int		golden_ratio;
}	t_mlx;

t_complex	ft_sum_complex(t_complex z1, t_complex z2);
t_complex	ft_square_complex(t_complex z);
void		ft_putstr_fd(int marker);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		ft_atoi_double(char *s);
void		ft_init(t_mlx *fractol);
void		ft_render(t_mlx *fractol);
void		ft_handel_pixels(int x, int y, t_mlx *fractol);
double		ft_scale(double num, double new_min,
				double new_max, double old_max);
void		ft_events(t_mlx *fractol);
void		ft_settings(t_mlx *fractol);
int			ft_handle_key(int keysym, t_mlx *fractol);
int			ft_handle_mouse(int button, int x, int y, t_mlx *fractol);
int			ft_close(t_mlx *fractol);
void		ft_bonus(t_mlx *fractol);
int			ft_atoi(const char *str);
void		ft_pixel_put(int x, int y, t_img *img, int color);
void		ft_set(t_mlx *fractol, char *s);
void		ft_set_julia(t_mlx *fractol, char *arg);
void		ft_set_julia_four(t_mlx *fractol, char *arg1, char *arg2);

#endif
