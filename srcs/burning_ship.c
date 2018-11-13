/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 20:30:58 by beborch           #+#    #+#             */
/*   Updated: 2018/10/12 23:37:02 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	calcul_ship(t_wind *wind, int y, int i)
{
	if (i == 1)
	{
		wind->ci = (y - WIN_Y / 2.0) / (0.5 * wind->zoom * WIN_Y)
			+ wind->start_y;
		wind->zr = 0;
		wind->zi = 0;
	}
	else if (i == 2)
	{
		wind->tmp = wind->zr;
		wind->zr = wind->tmp * wind->tmp - wind->zi * wind->zi + wind->cr;
		wind->zi = 2 * fabs(wind->zi * wind->tmp) + wind->ci;
	}
}

void	draw_ship(t_wind *wind)
{
	unsigned int	x;
	unsigned int	y;
	int				i;

	x = 0;
	while (x < WIN_X)
	{
		y = 0;
		wind->cr = 1.5 * (x - WIN_X / 2.0) / (0.5 * wind->zoom * WIN_X)
			+ wind->start_x;
		while (y < WIN_Y)
		{
			calcul_ship(wind, y, 1);
			i = -1;
			while ((wind->zr * wind->zr + wind->zi * wind->zi) <
			4.0 && ++i < wind->iteration)
				calcul_ship(wind, y, 2);
			drawing_color(wind, i, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(wind->mlx_ptr, wind->win_ptr, wind->img_ptr, 0, 0);
}
