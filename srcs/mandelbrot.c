/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:38:37 by beborch           #+#    #+#             */
/*   Updated: 2018/10/12 22:35:15 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	calcul_mandelbrot(t_wind *wind, int x, int i)
{
	if (i == 1)
	{
		wind->cr = 1.5 * (x - WIN_X / 2.0) / (0.5 * wind->zoom * WIN_X)
			+ wind->start_x;
		wind->zr = 0;
		wind->zi = 0;
	}
	else if (i == 2)
	{
		wind->tmp = wind->zr;
		wind->zr = wind->tmp * wind->tmp - wind->zi * wind->zi + wind->cr;
		wind->zi = 2.0 * wind->tmp * wind->zi + wind->ci;
	}
}

void	draw_mandelbrot(t_wind *wind)
{
	unsigned int	x;
	unsigned int	y;
	int				i;

	y = 0;
	while (y < WIN_Y)
	{
		wind->ci = (y - WIN_Y / 2.0) / (0.5 * wind->zoom * WIN_Y)
		+ wind->start_y;
		x = 0;
		while (x < WIN_X)
		{
			calcul_mandelbrot(wind, x, 1);
			i = -1;
			while ((wind->zr * wind->zr + wind->zi * wind->zi)
				< 4.0 && ++i < wind->iteration)
				calcul_mandelbrot(wind, x, 2);
			drawing_color(wind, i, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(wind->mlx_ptr, wind->win_ptr, wind->img_ptr, 0, 0);
}
