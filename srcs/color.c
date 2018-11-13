/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 20:28:10 by beborch           #+#    #+#             */
/*   Updated: 2018/10/13 01:25:24 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	drawing_color(t_wind *wind, int i, int x, int y)
{
	unsigned int		color;
	static unsigned int	g_color[81] = {
		0xf7df, 0xff5a, 0x07ff, 0x7ffa, 0xf7ff, 0xfc60, 0x9999, 0xff9c,
		0xf7bb, 0xff38, 0xff59, 0x001f, 0x895c, 0x05ff, 0x6b4d, 0xfdb8,
		0xa145, 0xddd0, 0x5cf4, 0x7fe0, 0xd343, 0xfea0, 0xdd24, 0x9772,
		0xfbea, 0x64bd, 0xffdb, 0xd8a7, 0x07ff, 0xf731, 0xe73f, 0x3666,
		0x0011, 0x0451, 0xbc21, 0xad55, 0x0320, 0xbdad, 0x8811, 0x5345,
		0x8800, 0xecaf, 0x8df1, 0x49f1, 0x2a69, 0x067a, 0x901a, 0xf8b2,
		0x1c9f, 0xd48e, 0xb104, 0xffde, 0x2444, 0xf81f, 0xdefb, 0xffdf,
		0x8410, 0x0400, 0xafe5, 0xf7fe, 0xfb56, 0xcaeb, 0x4810, 0xfffe,
		0xff9e, 0x7fe0, 0xffd9, 0xaedc, 0xf410, 0xe7ff, 0xffda, 0xd69a,
		0xfd0f, 0x2595, 0x867f, 0x839f, 0x7453, 0xb63b, 0xfffc, 0x07e0,
	};

	color = g_color[i];
	wind->data_img[((y * WIN_X + x) * 4)] =
	((color >> 11) & 0x1F) << wind->color;
	wind->data_img[((y * WIN_X + x) * 4) + 1] =
	((color >> 5) & 0x3F) << (wind->color - 1);
	wind->data_img[((y * WIN_X + x) * 4) + 2] =
	(color & 0x1F) << wind->color;
}
