/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 23:01:18 by beborch           #+#    #+#             */
/*   Updated: 2018/10/13 02:10:56 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	key_one(int key, t_wind *wind)
{
	if (key == 69)
		wind->zoom += 0.1;
	else if (key == 78)
		wind->zoom -= 0.1;
	else if (key == 8)
	{
		if (wind->color == 7)
			wind->color = 3;
		else
			wind->color++;
	}
	go_fractal(wind);
}

void	key_two(int key, t_wind *wind)
{
	if (key == 12)
		wind->iteration += 10;
	else if (key == 13)
		wind->iteration -= 10;
	else if (key == 123)
		wind->start_x -= 0.005;
	else if (key == 124)
		wind->start_x += 0.005;
	else if (key == 125)
		wind->start_y += 0.005;
	else if (key == 126)
		wind->start_y -= 0.005;
	go_fractal(wind);
}

int		get_key(int key, t_wind *wind)
{
	if (key == 69 || key == 78 || key == 8)
		key_one(key, wind);
	if (key == 12 || key == 13 || (key >= 123 && key <= 126))
		key_two(key, wind);
	if (key == 53)
		exit(0);
	return (0);
}

int		get_mouse(int mouse, int x, int y, t_wind *wind)
{
	if (mouse == 1 || mouse == 5)
	{
		wind->start_x += (x - WIN_X / 2) / (WIN_X / 2 * wind->zoom) / 8;
		wind->start_y += (x - WIN_Y / 2) / (WIN_Y / 2 * wind->zoom) / 8;
		wind->zoom += 0.2;
		if (x < WIN_X && y < WIN_Y)
		{
			wind->x = (double)x;
			wind->y = (double)y;
		}
		go_fractal(wind);
	}
	if (mouse == 2 || mouse == 4)
	{
		if (wind->zoom < 0.4)
			wind->zoom *= 0.2;
		else
			wind->zoom -= 0.2;
		go_fractal(wind);
	}
	return (0);
}

int		mouse_hook(int x, int y, t_wind *wind)
{
	if (x < WIN_X && y < WIN_Y && x > 0 && y > 0)
	{
		wind->x = (double)x;
		wind->y = (double)y;
		go_fractal(wind);
	}
	return (0);
}
