/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/23 23:26:29 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Le probleme vient peut etre de la fonction draw_line qui ne sait pas traçer quand coord_start > coord_end

int	math_coeff_circle(int radius, double angle, int *out)
{
	double	radian;
	double	filter;

	(void)radius; // Rayon de cercle
	(void)angle; // Angle de direction
	(void)out; // Resultat du calcul stockés dans un pointeurs
	(void)filter;
	filter = 1;
	ft_bzero(out, sizeof(int) * 2);
	radian = angle * (M_PI / 180);
	out[0] = radius * (cos(radian));
	out[1] = radius * (sin(radian));
	filter = out[0] + out[1];
	printf("\nDB X[%d]+Y[%d]->[%.2f]\n", out[0], out[1], filter);
	// if (filter % 90)
	// {
	// 	out[0] += out[0];
	// 	out[1] += out[1];
	// }
	return (EXIT_SUCCESS); // Retourne 0 (reussite) ou 1 (echec)
}
void	math_main(void)
{
	return ;
}
