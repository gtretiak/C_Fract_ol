/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_iterator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:46:34 by gtretiak          #+#    #+#             */
/*   Updated: 2025/06/14 19:01:54 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#ifndef ITER
# define ITER 100
#endif

int     main(void)
{
	typedef struct	s_complex
	{
		double	real;
		double	imag;
	} t_complex;
        int     i;
        double  tmp;
        t_complex       z;
        t_complex       c;

        z.real = 0;
        z.imag = 0;
        c.real = -0.8;
        c.imag = 0.156;
        i = 0;
        while (++i <= ITER)
        {
                tmp = (z.real * z.real) - (z.imag * z.imag);
                z.imag = 2 * z.real * z.imag;
                z.real = tmp;
                z.real += c.real;
                z.imag += c.imag;
                printf("Iter:%d -> real:%f; imag:%f\n", i, z.real, z.imag);
        }
}
