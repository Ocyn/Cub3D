/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/06/05 17:01:57 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	math_circle(int radius, double angle, int *out)
{
	double	radian;
	double	filter;

	(void)radius;
	(void)angle;
	(void)out;
	(void)filter;
	filter = 1;
	ft_bzero(out, sizeof(int) * 2);
	radian = angle * (MATH_PI / 180);
	out[0] = radius * (cos(radian));
	out[1] = radius * (sin(radian));
	filter = out[0] + out[1];
	return (EXIT_SUCCESS);
}

void	math_main(void)
{
	return ;
}
