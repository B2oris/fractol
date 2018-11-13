/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:27:30 by beborch           #+#    #+#             */
/*   Updated: 2018/10/12 23:35:24 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	calcul_julia(t_wind *wind, int x, int i)
{
	double			ci;
	double			cr;

	ci = (wind->y - WIN_Y / 2.0) / (WIN_X / 2.0);
	cr = (wind->x - WIN_X / 2.0) / (WIN_X / 2.0);
	if (i == 1)
	{
		wind->zr = wind->cr;
		wind->zi = 1.5 * (x - WIN_X / 2.0) / (0.5 * wind->zoom * WIN_X)
			+ wind->start_x;
	}
	else if (i == 2)
	{
		wind->tmp = wind->zr;
		wind->zr = wind->tmp * wind->tmp - wind->zi * wind->zi + cr;
		wind->zi = 2 * wind->tmp * wind->zi + ci;
	}
}

void	draw_julia(t_wind *wind)
{
	unsigned int	x;
	unsigned int	y;
	int				i;

	y = 0;
	while (y < WIN_Y)
	{
		x = 0;
		wind->cr = (y - WIN_Y / 2.0) / (0.5 * wind->zoom * WIN_Y)
			+ wind->start_y;
		while (x < WIN_X)
		{
			calcul_julia(wind, x, 1);
			i = -1;
			while ((wind->zr * wind->zr + wind->zi * wind->zi)
				< 4.0 && ++i < wind->iteration)
				calcul_julia(wind, x, 2);
			drawing_color(wind, i, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(wind->mlx_ptr, wind->win_ptr, wind->img_ptr, 0, 0);
}
