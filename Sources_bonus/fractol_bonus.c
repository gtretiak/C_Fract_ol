/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:30:24 by gtretiak          #+#    #+#             */
/*   Updated: 2025/01/30 12:28:00 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int argc, char **argv)
{
	char	*error;
	t_mlx	fractol;

	error = "Invalid argument(s). Insert:\n"
		"\"<Program name> <Multibrot>\";\n";
	if (argc == 2 && !ft_strncmp(argv[1], "Multibrot", 9))
	{
		fractol.name = argv[1];
		ft_putstr_fd("Fractol set has been called\n", 1);
		ft_init(&fractol);
		ft_render(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
	{
		ft_putstr_fd(error, 2);
		exit(2);
	}
}
