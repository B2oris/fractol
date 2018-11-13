/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 13:38:07 by beborch           #+#    #+#             */
/*   Updated: 2018/10/12 23:33:43 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_windows(t_wind *wind)
{
	wind->mlx_ptr = mlx_init();
	wind->win_ptr = mlx_new_window(wind->mlx_ptr, WIN_X, WIN_Y, "Fractol");
	wind->img_ptr = mlx_new_image(wind->mlx_ptr, WIN_X, WIN_Y);
	wind->data_img = (unsigned char *)mlx_get_data_addr(wind->img_ptr,
		&wind->bpp, &wind->s_l, &wind->endian);
	wind->zoom = 0.5;
	wind->color = 3;
	wind->start_x = -0.5;
	wind->start_y = 0;
	wind->iteration = 142;
}

void	usage(void)
{
	ft_putstr("Usage :\n--> Julia\n--> Mandelbrot\n--> Ship\n");
	exit(0);
}

void	go_fractal(t_wind *wind)
{
	ft_memset(wind->data_img, 0, WIN_X * WIN_Y * 4);
	if (ft_strcmp(wind->map, "Julia") == 0)
		draw_julia(wind);
	else if (ft_strcmp(wind->map, "Mandelbrot") == 0)
		draw_mandelbrot(wind);
	else if (ft_strcmp(wind->map, "Ship") == 0)
		draw_ship(wind);
	else
		usage();
}

int		main(int argc, char *argv[])
{
	t_wind wind;

	wind.x = (double)0;
	wind.y = (double)0;
	set_windows(&wind);
	mlx_key_hook(wind.win_ptr, get_key, &wind);
	if (argc == 2)
	{
		ft_strcpy(wind.map, argv[1]);
		go_fractal(&wind);
	}
	else
		usage();
	mlx_hook(wind.win_ptr, 6, 3, mouse_hook, &wind);
	mlx_mouse_hook(wind.win_ptr, get_mouse, &wind);
	mlx_loop(wind.mlx_ptr);
}
