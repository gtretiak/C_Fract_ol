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
# include <X11/X.h> // for using the event and mask definitions and macros defined in the header 
# include <X11/keysym.h> // for using key symbol macros for keyboard input, like XK_Escape, XK_q, etc
# include <stdlib.h>
# include "minilibx-linux/mlx.h"

# ifndef HEIGHT
#  define HEIGHT 800 // defined the size of the window (height)
# endif

# ifndef WIDTH
#  define WIDTH 800 // defined the size of the window (width)
# endif

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img // here pixels are stored before being shown in a window
{
	void	*img; // a pointer to the image object created by MiniLibX
	char	*pixels; // a pointer to the raw pixel data of the image
	int		bpp; // Bits per pixel: usually 32 for RGBA (8 bits per channel (color))
	int		line_len; // number of bytes per row of pixels (may be more than image width due to padding) 
	int		endian; // important for color byte order
}	t_img;

typedef struct s_mlx 
{
	void	*mlx; // a pointer to the MLX connection
	void	*win; // a pointer to the created window
	t_img	img; // embedded image structure
	char	*name; // fractal name
	double	escape_value;
	double	shift_x; // horizontal shift
	double	shift_y; // vertical shift
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		iter;
	int		dance;
	int		golden_ratio;
}	t_mlx;

// Complex computations
t_complex	ft_sum_complex(t_complex z1, t_complex z2);
t_complex	ft_square_complex(t_complex z);

// Initialization and settings
void		ft_init(t_mlx *fractol);
void		ft_settings(t_mlx *fractol);
void		ft_set(t_mlx *fractol, char *s);
void		ft_set_julia(t_mlx *fractol, char *arg);
void		ft_set_julia_four(t_mlx *fractol, char *arg1, char *arg2);

// Utils
void		ft_putstr_fd(int marker);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		ft_atoi_double(char *s);
int			ft_atoi(const char *str);

// Rendering
void		ft_render(t_mlx *fractol);
void		ft_handel_pixels(int x, int y, t_mlx *fractol);
void		ft_pixel_put(int x, int y, t_img *img, int color);
double		ft_scale(double num, double new_min,
				double new_max, double old_max);

// Events
void		ft_events(t_mlx *fractol);
int			ft_handle_key(int keysym, t_mlx *fractol);
int			ft_handle_mouse(int button, int x, int y, t_mlx *fractol);
int			ft_close(t_mlx *fractol);
void		ft_bonus(t_mlx *fractol);

#endif
