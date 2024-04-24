/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:53:57 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/24 20:32:39 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_data_struct(t_data *data, int argc, char **argv)
{
	if (!data)
		return (err_return(EXIT_FAILURE, "Memory issue", 1));
	res_data_struct(data, 0);
	if (argc != 2)
		return (err_return(EXIT_FAILURE, "Invalid argument format", 0));
	data->arg_nb = argc;
	data->arg_tab = argv;
	return (EXIT_SUCCESS);
}

int	init_texture_struct(t_data *data, t_tex	*texture)
{
	texture->id = mlx_xpm_file_to_image(data->mlx.init, texture->file, &texture->wi, &texture->he);
	if (!texture->id)
		return (err_return(EXIT_FAILURE, "XPM file failed to load", 3));
	texture->life = (texture->id != NULL);
	return (EXIT_SUCCESS);
}

int	init_minimap_struct(t_data *data, t_minimap *minimap)
{
	if (!data)
		return (err_return(EXIT_FAILURE, "Memory issue", 4));
	res_minimap_struct(minimap);
	minimap->win_size[0] = data->mlx.win_w / MINIMAP_SCALE;
	minimap->win_size[1] = data->mlx.win_h / MINIMAP_SCALE;
	minimap->win_pos[0] = MINIMAP_POS_X;
	minimap->win_pos[1] = MINIMAP_POS_Y;
	*minimap->y = (minimap->win_size[1] / 2) - data->player.ypos * data->mlx.game_scale;
	*minimap->x = (minimap->win_size[0] / 2) - data->player.xpos * data->mlx.game_scale;
	printf("\nDB:\t\t[X:%d][Y:%d] / 2\n", minimap->win_size[0], minimap->win_size[1]);
	printf("\nDB2:\t\t - [X:%lld][Y:%lld] * [Scale:%d]\n", data->player.xpos, data->player.ypos, data->mlx.game_scale);
	printf("\nDB3:\t\t[X:%.1f][Y:%.1f]\n", minimap->x_y[0], minimap->x_y[1]);
	minimap->data = data;
	return (EXIT_SUCCESS);
}

int	init_mlx_struct(t_data *data, t_mlx *mlx)
{
	if (!data)
		return (err_return(EXIT_FAILURE, "Memory issue", 3));
	mlx->init = mlx_init();
	if (!mlx->init)
		return (err_return(EXIT_FAILURE, "MLX init failed", 3));
	mlx_get_screen_size(mlx->init, &mlx->win_w, &mlx->win_h);
	mlx->game_scale = GAME_SCALING;
	mlx->win_h /= 2;
	mlx->win_w /= 2;
	mlx->win_hmid = (mlx->win_h / 2);
	mlx->win_wmid = (mlx->win_w / 2);
	mlx->map_limit[0] = data->map.xlen * mlx->game_scale;
	mlx->map_limit[1] = data->map.ylen * mlx->game_scale;
	mlx->speed = PLAYER_SPEED;
	mlx->speed /= mlx->game_scale;
	init_minimap_struct(data, &data->minimap);
	mlx->data = data;
	mlx->minimap = &data->minimap;
	return (EXIT_SUCCESS);
}

int	init_player_struct(t_data *data, t_player *pl, t_map map)
{
	if (!pl || !map.map || !map.map[0] || !map.map[0][0])
		return (err_return(EXIT_FAILURE, "Memory issue", 1));
	res_player_struct(pl, 0);
	while (pl->ypos < map.ylen && !ft_strchr(map.map[pl->ypos], 'N') \
	&& !ft_strchr(map.map[pl->ypos], 'S') && !ft_strchr(map.map[pl->ypos], 'E') \
	&& !ft_strchr(map.map[pl->ypos], 'W'))
		pl->ypos++;
	while (map.map[pl->ypos][pl->xpos] && map.map[pl->ypos][pl->xpos] != 'N' \
	&& map.map[pl->ypos][pl->xpos] != 'S' && map.map[pl->ypos][pl->xpos] != 'E' \
	&& map.map[pl->ypos][pl->xpos] != 'W')
		pl->xpos++;
	if (pl->xpos == map.xlen && pl->ypos == map.ylen)
		return (err_return(EXIT_FAILURE, "Player position not found", 1));
	pl->compass = map.map[pl->ypos][pl->xpos];
	pl->x_y[0] = (double)pl->xpos;
	pl->x_y[1] = (double)pl->ypos;
	if (pl->compass == 'O')
		pl->angle += 90;
	if (pl->compass == 'E')
		pl->angle -= 90;
	if (pl->compass == 'S')
		pl->angle += 180;
	pl->angle -= 90;
	pl->data = data;
	return (EXIT_SUCCESS);
}
