/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 13:28:36 by beborch           #+#    #+#             */
/*   Updated: 2018/10/09 23:49:47 by beborch          ###   ########.fr       */
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

typedef struct s_complex
{
	double x;
	double y;
}				t_complex;

typedef struct s_wind
{
void    *mlx_ptr;
void    *win_ptr;
void    *img_ptr;
unsigned char *data_img;
int     bpp;
int     endian;
int     s_l;
int		color;
char	map[20];
float		zoom;

double	start_x;
double	start_y;

int test;

double x;
double y;

int iteration;
// t_complex complex;


}               t_wind;

#endif