/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:46:00 by aammirat          #+#    #+#             */
/*   Updated: 2024/06/03 13:32:51 by aammirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	re_pixeltoimg(t_img *img, int x, int y, int color)
{
	if ((size_t)x >= (size_t)img->width || (size_t)y >= (size_t)img->height)
		return ;
	((int *)img->data)[y * (img->width) + x] = color;
}

void	draw_straight_line(t_img *img, int x, int y[2], int color)
{
	int	i;

	i = y[0];
	while (i < y[1])
	{
		re_pixeltoimg(img, x, i, color);
		i++;
	}
}

int	re_take_img_pixel(t_img *text, int x, int y)
{
	if ((size_t)x >= (size_t)text->width || (size_t)y >= (size_t)text->height)
		return (0);
	return (((int *)text->data)[y * (text->width) + x]);
}
