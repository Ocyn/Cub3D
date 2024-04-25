/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 02:24:18 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/25 23:52:06 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	misc_clear_screen(t_mlx *mlx)
{
	//ft_memset((char *)img->data, 0x0, (img->width * img->height) * 4);
	draw_square_snap(mlx, (size_t[2]){0, 0}, (size_t[2]){mlx->win_w, mlx->win_h}, 0x0);
}

inline void	misc_fill_screen(t_img *img, size_t one[2], size_t two[2], int color)
{
	ft_memset((int *)(img->data) + ((img->width * one[1]) + one[0]) \
	, (int)color, 4 * (img->width * two[1]) + two[0]);
}

inline void	misc_default_game(t_data *data, int mode)
{
	t_minimap	*minimap;
	t_player	*player;
	t_mlx		*mlx;

	player = &data->player;
	minimap = &data->minimap;
	mlx = &data->mlx;
	mlx->deadzone = (10 * data->mlx.game_scale) % data->mlx.win_h;
	if (mode == 0)
	{
		misc_clear_screen(mlx);
		re_draw_environnment(data, 1);
	}
	if (mode == 1)
	{
		mlx->game_scale = GAME_SCALING;
		*player->x = player->xpos;
		*player->y = player->ypos;
		player->angle = 0;
		*minimap->y = (minimap->size[1] / 2) - player->ypos * mlx->game_scale;
		*minimap->x = (minimap->size[0] / 2) - player->xpos * mlx->game_scale;
	}
}

void	misc_opposite_color(int *color)
{
	color[0] = 255 - color[0];
	color[1] = 255 - color[1];
	color[2] = 255 - color[2];
}

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
