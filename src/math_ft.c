/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/23 20:59:10 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	math_coeff_circle(int radius, int angle, int *out)
{
	double	radian;

	(void)radius; // Rayon de cercle
	(void)angle; // Angle de direction
	(void)out; // Resultat du calcul stockés dans un pointeurs
	ft_bzero(out, sizeof(int) * 2);
	radian = angle * (MATH_PI / 180);
	out[0] = radius * (sin(radian));
	out[1] = radius * (cos(radian));
	return (EXIT_SUCCESS); // Retourne 0 (reussite) ou 1 (echec)
}
void	math_main(void)
{
	return ;
}
