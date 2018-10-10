// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 13:38:07 by beborch           #+#    #+#             */
/*   Updated: 2018/10/05 18:41:03 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    set_windows(t_wind *wind)
{
    wind->mlx_ptr = mlx_init();
    wind->win_ptr = mlx_new_window(wind->mlx_ptr, WIN_X, WIN_Y, "Fractol");
    wind->img_ptr = mlx_new_image(wind->mlx_ptr, WIN_X, WIN_Y);
    wind->data_img = (unsigned char *)mlx_get_data_addr(wind->img_ptr, &wind->bpp, &wind->s_l, &wind->endian);
	// mlx_string_put(wind->mlx_ptr, wind->win_ptr, WIN_X / 2, WIN_Y / 2, 200200200, "fractol");
	wind->zoom = 0.5;
	wind->color = 3;
	wind->start_x = -0.75;
	wind->start_y = 0;
	wind->iteration = 142;
}

void	usage(void)
{
    ft_putstr("Usage :\n--> Julia\n--> Mandelbrot\n");
    exit(0);
}

void	filling_white(t_wind *wind, int x, int y)
{
	int i;

	i = (y * WIN_X + x) * 4;
	wind->data_img[i] = 255;
	wind->data_img[i + 1] = 0;
	wind->data_img[i + 2] = 0;
}

void	draw_mandelbrot(t_wind *wind)
{
	const unsigned int COLOR_TABLE[] = {
    0xf7df, 0xff5a, 0x07ff, 0x7ffa, 0xf7ff, 0xf7bb, 0xff38, 0xff59, 0x001f, 0x895c, 
    0xa145, 0xddd0, 0x5cf4, 0x7fe0, 0xd343, 0xfbea, 0x64bd, 0xffdb, 0xd8a7, 0x07ff, 
    0x0011, 0x0451, 0xbc21, 0xad55, 0x0320, 0xbdad, 0x8811, 0x5345, 0xfc60, 0x9999, 
    0x8800, 0xecaf, 0x8df1, 0x49f1, 0x2a69, 0x067a, 0x901a, 0xf8b2, 0x05ff, 0x6b4d, 
    0x1c9f, 0xd48e, 0xb104, 0xffde, 0x2444, 0xf81f, 0xdefb, 0xffdf, 0xfea0, 0xdd24, 
    0x8410, 0x0400, 0xafe5, 0xf7fe, 0xfb56, 0xcaeb, 0x4810, 0xfffe, 0xf731, 0xe73f, 
    0xff9e, 0x7fe0, 0xffd9, 0xaedc, 0xf410, 0xe7ff, 0xffda, 0xd69a, 0x9772, 0xfdb8, 
    0xfd0f, 0x2595, 0x867f, 0x839f, 0x7453, 0xb63b, 0xfffc, 0x07e0, 0x3666, 0xff9c, 
    0xf81f, 0x8000, 0x6675, 0x0019, 0xbaba, 0x939b, 0x3d8e, 0x7b5d, 0x07d3, 0x4e99, 
    0xc0b0, 0x18ce, 0xf7ff, 0xff3c, 0xff36, 0xfef5, 0x0010, 0xffbc, 0x8400, 0x6c64, 
    0xfd20, 0xfa20, 0xdb9a, 0xef55, 0x9fd3, 0xaf7d, 0xdb92, 0xff7a, 0xfed7, 0xcc27, 
    0xfe19, 0xdd1b, 0xb71c, 0x8010, 0xf800, 0xbc71, 0x435c, 0x8a22, 0xfc0e, 0xf52c, 
    0x2c4a, 0xffbd, 0xa285, 0xc618, 0x867d, 0x6ad9, 0x7412, 0xffdf, 0x07ef, 0x4416, 
    0xd5b1, 0x0410, 0xddfb, 0xfb08, 0x471a, 0xec1d, 0xd112, 0xf6f6, 0xffff, 0xf7be, 
    0xffe0, 0x9e66, 0x0000
};


	int max_itera = 142;
	
	unsigned int x = 0;
	unsigned int y = 0;

	double p_i;
	double p_r;
	double new_r;
	double new_i;
	double old_r;
	double old_i;
	int i;

	while (y < WIN_Y)
	{
		p_i = (y - WIN_Y / 2.0) / (0.5 * wind->zoom * WIN_Y) + wind->start_y;
		x = 0;
		while(x < WIN_X)
		{
			p_r = 1.5 * (x - WIN_X / 2.0) / (0.5 * wind->zoom * WIN_X) + wind->start_x;
			new_r = 0;
			new_i = 0;
			old_i = 0;
			old_r = 0;
			i = 0;
			while ((new_r * new_r + new_i * new_i) < 4.0 && i < max_itera)
			{
				old_r = new_r;
				old_i = new_i;
				new_r = old_r * old_r - old_i * old_i + p_r;
				new_i = 2.0 * old_r * old_i + p_i;
				++i;
			}
			unsigned int color = COLOR_TABLE[i];
			wind->data_img[((y * WIN_X + x) * 4)] = ((color >> 11) & 0x1F) << wind->color;
			wind->data_img[((y * WIN_X + x) * 4) + 1] = ((color >> 5) & 0x3F) << (wind->color - 1);
			wind->data_img[((y * WIN_X + x) * 4) + 2] = (color & 0x1F) << wind->color;
			x++;
		}
		y++;
	}
	ft_bn();
	ft_putnbr(x);
	ft_bn();
	ft_putnbr(y);
	ft_bn();
	ft_putnbr(i);
	ft_bn();
	ft_putstr("fin \n");
	mlx_put_image_to_window(wind->mlx_ptr, wind->win_ptr, wind->img_ptr, 0, 0);
}

void	draw_julia(t_wind *wind)
{
	ft_putstr("enter julia\n");
	
	const unsigned int COLOR_TABLE[] = {
    0xf7df, 0xff5a, 0x07ff, 0x7ffa, 0xf7ff, 0xf7bb, 0xff38, 0xff59, 0x001f, 0x895c, 
    0xa145, 0xddd0, 0x5cf4, 0x7fe0, 0xd343, 0xfbea, 0x64bd, 0xffdb, 0xd8a7, 0x07ff, 
    0x0011, 0x0451, 0xbc21, 0xad55, 0x0320, 0xbdad, 0x8811, 0x5345, 0xfc60, 0x9999, 
    0x8800, 0xecaf, 0x8df1, 0x49f1, 0x2a69, 0x067a, 0x901a, 0xf8b2, 0x05ff, 0x6b4d, 
    0x1c9f, 0xd48e, 0xb104, 0xffde, 0x2444, 0xf81f, 0xdefb, 0xffdf, 0xfea0, 0xdd24, 
    0x8410, 0x0400, 0xafe5, 0xf7fe, 0xfb56, 0xcaeb, 0x4810, 0xfffe, 0xf731, 0xe73f, 
    0xff9e, 0x7fe0, 0xffd9, 0xaedc, 0xf410, 0xe7ff, 0xffda, 0xd69a, 0x9772, 0xfdb8, 
    0xfd0f, 0x2595, 0x867f, 0x839f, 0x7453, 0xb63b, 0xfffc, 0x07e0, 0x3666, 0xff9c, 
    0xf81f, 0x8000, 0x6675, 0x0019, 0xbaba, 0x939b, 0x3d8e, 0x7b5d, 0x07d3, 0x4e99, 
    0xc0b0, 0x18ce, 0xf7ff, 0xff3c, 0xff36, 0xfef5, 0x0010, 0xffbc, 0x8400, 0x6c64, 
    0xfd20, 0xfa20, 0xdb9a, 0xef55, 0x9fd3, 0xaf7d, 0xdb92, 0xff7a, 0xfed7, 0xcc27, 
    0xfe19, 0xdd1b, 0xb71c, 0x8010, 0xf800, 0xbc71, 0x435c, 0x8a22, 0xfc0e, 0xf52c, 
    0x2c4a, 0xffbd, 0xa285, 0xc618, 0x867d, 0x6ad9, 0x7412, 0xffdf, 0x07ef, 0x4416, 
    0xd5b1, 0x0410, 0xddfb, 0xfb08, 0x471a, 0xec1d, 0xd112, 0xf6f6, 0xffff, 0xf7be, 
    0xffe0, 0x9e66, 0x0000
};


	int max_itera = 142;
	
	unsigned int x = 0;
	unsigned int y = 0;
	wind->start_x = 0;
	wind->start_y = 0;
	double rc = (wind->x - WIN_X / 2.0) / (WIN_X / 2.0);
	double ic = (wind->y - WIN_Y / 2.0) / (WIN_X / 2.0);

	// double rc = -1;
	// double ic = 0.0;

	// double ci; 
	double cr; // p_i 
	double zr; // new_r
	double zi; // p_r
	int i; 

	double tmp; // old_r

	while (y < WIN_Y)
	{
		x = 0;
		cr = (y - WIN_Y / 2.0) / (0.5 * wind->zoom * WIN_Y) + wind->start_y;
		while(x < WIN_X)
		{
			zr = cr;
			zi = 1.5 * (x - WIN_X / 2.0) / (0.5 * wind->zoom * WIN_X) + wind->start_x;
			i = 0;
			while ((zr * zr + zi * zi) < 4.0 && i < wind->iteration)
			{
				tmp = zr;
				zr = tmp * tmp - zi * zi + rc;
				zi = 2 * tmp * zi + ic;
				++i;
			}
			unsigned int color = COLOR_TABLE[i];
			wind->data_img[((y * WIN_X + x) * 4)] = ((color >> 11) & 0x1F) << wind->color;
			wind->data_img[((y * WIN_X + x) * 4) + 1] = ((color >> 5) & 0x3F) << (wind->color - 1);
			wind->data_img[((y * WIN_X + x) * 4) + 2] = (color & 0x1F) << wind->color;
			x++;
		}
		y++;
	}


	ft_putstr("print julia\n");
	mlx_put_image_to_window(wind->mlx_ptr, wind->win_ptr, wind->img_ptr, 0, 0);
}

void    go_fractal(t_wind *wind)
{
    ft_memset(wind->data_img, 0, WIN_X * WIN_Y * 4);
	if (ft_strcmp(wind->map, "Julia") == 0)
    {
        ft_putstr("julia");
		draw_julia(wind);
    }
    else if (ft_strcmp(wind->map, "Mandelbrot") == 0)
    {
        draw_mandelbrot(wind);
        ft_putstr("Mandelbrot");
    }
    else
        usage();
}

int		get_key(int key, t_wind *wind)
{
    ft_bn();
	ft_putnbr(key);
	ft_bn();
	if (key == 69 || key == 78)
	{
		if (key == 69)
			wind->zoom += 01;
		else
			wind->zoom -= 0.1;
		go_fractal(wind);
	}
	if (key == 8)
	{
		if (wind->color == 7)
			wind->color = 3;
		else
			wind->color++;
		go_fractal(wind);
	}
	if (key == 12 || key == 13)
	{
		if (key == 12)
			wind->iteration += 10;
		if (key == 13)
			wind->iteration -= 10;
		go_fractal(wind);
	}
	if (key >= 123 && key <= 126)
	{
		if (key == 123)
			wind->start_x -= 0.005;
		if (key == 124)
			wind->start_x += 0.005;
		if (key == 125)
			wind->start_y += 0.005;
		if (key == 126)
			wind->start_y -= 0.005;
		go_fractal(wind);
	}
	if (key == 53)
        exit(0);
    return (0);
}

int		get_mouse(int mouse, int x, int y, t_wind *wind)
{
	ft_putnbr(mouse);
	ft_bn();
	// ft_putnbr(x);
	ft_bn();
	// ft_putnbr(y);
	ft_bn();
	if (mouse == 1)
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
	if (mouse == 2)
	{
		if (wind->zoom < 0.4)
			wind->zoom *= 0.2;
		else
			wind->zoom -= 0.2;
		go_fractal(wind);
	}
	return(0);
}

int		mouse_hook(int x, int y, t_wind *wind)
{
	if (x < WIN_X && y < WIN_Y && x > 0 && y > 0)
	{
		wind->x = (double)x;
		wind->y = (double)y;
		ft_putstr("no seg\n");
		go_fractal(wind);
	}
	return(0);
}
// event 17 croix

int     main(int argc, char *argv[])
{
    t_wind wind;
	wind.x = (double)0;
	wind.y = (double)0;
    set_windows(&wind);
    mlx_key_hook(wind.win_ptr, get_key, &wind);
	if (argc == 2)
    {
		ft_strcpy(wind.map, argv[1]);
		ft_putstr(wind.map);
        go_fractal(&wind);
	}
	mlx_hook(wind.win_ptr, 6, 3, mouse_hook, &wind);
    printf("%p avant\n",&wind);
	mlx_mouse_hook(wind.win_ptr, get_mouse, &wind);
	mlx_loop(wind.mlx_ptr);
}