/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/06/19 10:29:06 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_file(char *file)
{
	int	fd;

	fd = 0;
	if (!file)
		return (EXIT_FAILURE);
	if (ft_strlen(file) - me_find_str_in_str(file, ".cub") != 4)
		return (err_return(EXIT_FAILURE, "Invalid file name", 1));
	fd = open(file, O_RDONLY);
	if (fd < 2)
	{
		err_stderr(1);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	parse_map_borders(t_map map, t_player player)
{
	char		**temp;
	long long	y;

	y = 0;
	temp = me_tabdup(map.map, me_tablen(map.map));
	if (!temp)
		return (err_return(EXIT_FAILURE, "Map cloning failed", 2));
	if (misc_player_location(map, &player.ypos, &player.xpos))
		return (s_freetab(temp, me_tablen(temp)) \
		, err_return(EXIT_FAILURE, "No player found", 2));
	ff_diffusion(temp, player.ypos, player.xpos, '1');
	if (!temp)
		return (err_return(EXIT_FAILURE, "Diffusion failed", 2));
	while (temp && temp[y] && temp[y])
	{
		if (temp[y][0] == '*' || temp[y][ft_strlen(temp[y]) - 2] == '*')
			return (s_freetab(temp, me_tablen(temp)) \
			, err_return(EXIT_FAILURE, "Side wall breach", 2));
		y++;
	}
	if (ft_strchr(temp[0], '*') || ft_strchr(temp[y - 1], '*'))
		return (s_freetab(temp, me_tablen(temp)) \
		, err_return(EXIT_FAILURE, "Top / Bottom wall breach", 2));
	temp = s_freetab(temp, me_tablen(temp));
	return (EXIT_SUCCESS);
}

int	parse_map(t_map map, t_player player)
{
	long long	my;
	size_t		ct;

	my = 0;
	ct = 0;
	while (my < map.ylen)
	{
		if (me_str2strcmp(map.map[my], "01NSWE \n"))
			return (err_return(EXIT_FAILURE, "Invalid character", 1));
		ct += me_strchrn(map.map[my], 'N') + me_strchrn(map.map[my], 'S') \
		+ me_strchrn(map.map[my], 'W') + me_strchrn(map.map[my], 'E');
		if (ct > 1)
			return (err_return(EXIT_FAILURE, "Invalid player number", 1));
		my++;
	}
	if (parse_map_borders(map, player))
		return (err_return(EXIT_FAILURE, "Map not fully closed", 1));
	return (EXIT_SUCCESS);
}

int	parse_main(t_data *data)
{
	char	*file;

	if (!data)
		return (err_return(EXIT_FAILURE, "Memory issue", 0));
	file = data->arg_tab[1];
	if (parse_file(file))
		return (err_return(EXIT_FAILURE, "Parse file failed", 0));
	if (init_map_struct(data, &data->map, file))
		return (err_return(EXIT_FAILURE, "Map init failed", 0));
	if (init_player_struct(data, &data->player, data->map))
		return (err_return(EXIT_FAILURE, "Player init failed", 0));
	if (parse_map(data->map, data->player))
		return (err_return(EXIT_FAILURE, "Parse map failed", 0));
	return (EXIT_SUCCESS);
}
