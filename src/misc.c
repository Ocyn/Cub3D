/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 02:24:18 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/10 02:40:31 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	misc_player_location(t_map map, long long *y, long long *x)
{
	*y = 0;
	*x = 0;
	if (!map.map)
		return (err_return(EXIT_FAILURE, "Memory issue: Map not found", 1));
	while (!ft_strchr(map.map[*y], 'N') \
	&& !ft_strchr(map.map[*y], 'S') \
	&& !ft_strchr(map.map[*y], 'E') \
	&& !ft_strchr(map.map[*y], 'W') && *y <= map.ylen)
		(*y)++;
	while (map.map[*y][*x] != 'N' \
	&& map.map[*y][*x] != 'S' \
	&& map.map[*y][*x] != 'E' \
	&& map.map[*y][*x] != 'W' && map.map[*y][*x])
		(*x)++;
	if (*x == map.xlen && *y == map.ylen)
		return (err_return(EXIT_FAILURE, "Player position not found", 1));
	return (EXIT_SUCCESS);
}
