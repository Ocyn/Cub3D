/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/06/12 14:58:12 by aammirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	dist(double a, double b)
{
	return (sqrt(a * a + b * b));
}

double	approchy(t_data *data, double *xyangle, int stepx, double *posty)
{
	double	cos_a;
	int		postx;
	double	stepy;

	if (stepx == 0)
	{
		*posty = 0;
		return (0);
	}
	cos_a = cos(xyangle[2]);
	stepy = stepx * tan(xyangle[2]);
	postx = (int)xyangle[0] + (stepx > 0);
	*posty = xyangle[1] + stepy * fabs(postx - xyangle[0]);
	while (*posty > 0 && postx > 0 && postx < data->map.xlen \
	&& *posty < data->map.ylen \
	&& data->map.map[(size_t) * posty] \
	[(size_t)(postx) - (cos_a > 0)] != '1')
	{
		*posty += stepy;
		postx += stepx;
	}
	return (dist(*posty - *data->player.y, postx - *data->player.x));
}

double	approchx(t_data *data, double *xyangle, int stepy, double *postx)
{
	double	sin_a;
	int		posty;
	double	stepx;

	if (stepy == 0)
	{
		*postx = 0;
		return (0);
	}
	sin_a = sin(xyangle[2]);
	stepx = stepy / tan(xyangle[2]);
	posty = (int)xyangle[1] + (stepy > 0);
	*postx = xyangle[0] + stepx * fabs(posty - xyangle[1]);
	while (posty > 0 && *postx > 0 && *postx < data->map.xlen \
	&& posty < data->map.ylen \
	&& data->map.map[(size_t)posty - (sin_a > 0)] \
	[(size_t) * postx] != '1')
	{
		posty += stepy;
		*postx += stepx;
	}
	return (dist(posty - *data->player.y, *postx - *data->player.x));
}

double	rc_calc(t_data *data, t_rc *rc, double *size, double angle)
{
	rc->xyangle[2] = (angle * M_PI) / 180.0;
	rc->a = approchx(data, rc->xyangle, rc->stepy, &rc->postx);
	rc->b = approchy(data, rc->xyangle, rc->stepx, &rc->posty);
	if ((rc->a > rc->b && rc->b != 0) || rc->a == 0)
	{
		if (rc->stepx == 1)
			size[0] = 1;
		else
			size[0] = 2;
		rc->wall_dist = rc->b * fabs(cos(((angle \
		- data->player.angle) * M_PI / 180)));
		size[1] = rc->posty - (int)rc->posty;
	}
	else
	{
		if (rc->stepy == 1)
			size[0] = 3;
		else
			size[0] = 4;
		rc->wall_dist = rc->a * fabs(cos(((angle - \
		data->player.angle) * M_PI / 180)));
		size[1] = rc->postx - (int)rc->postx;
	}
	return ((data->mlx.win_h / rc->wall_dist));
}

double	rc_main(t_data *data, double angle, double *size)
{
	t_rc	rc;

	rc.postx = 0;
	rc.posty = 0;
	rc.wall_dist = 0;
	if (angle > 360)
		angle = angle - 360;
	if (angle < 0)
		angle = 360 + angle;
	if (angle < 270 && angle > 90)
		rc.stepx = 1;
	else if (angle == 270 || angle == 90)
		rc.stepx = 0;
	else
		rc.stepx = -1;
	if (angle < 180)
		rc.stepy = -1;
	else if (angle == 0 || angle == 180)
		rc.stepy = 0;
	else
		rc.stepy = 1;
	rc.xyangle[0] = *data->player.x;
	rc.xyangle[1] = *data->player.y;
	return (rc_calc(data, &rc, size, angle));
}
