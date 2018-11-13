/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 13:28:36 by beborch           #+#    #+#             */
/*   Updated: 2018/10/13 02:02:50 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_X (800)
# define WIN_Y (800)

# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct				s_wind
{
	void					*mlx_ptr;
	void					*win_ptr;
	void					*img_ptr;
	unsigned char			*data_img;
	int						bpp;
	int						endian;
	int						s_l;
	int						color;
	char					map[20];
	float					zoom;

	double					start_x;
	double					start_y;

	double					x;
	double					y;

	int						iteration;

	double					ci;
	double					cr;
	double					zr;
	double					zi;
	double					tmp;

}							t_wind;

void						go_fractal(t_wind *wind);
void						drawing_color(t_wind *wind, int i, int x, int y);
void						draw_mandelbrot(t_wind *wind);
void						draw_ship(t_wind *wind);
void						draw_julia(t_wind *wind);
int							get_mouse(int mouse, int x, int y, t_wind *wind);
int							mouse_hook(int x, int y, t_wind *wind);
int							get_key(int key, t_wind *wind);

#endif
