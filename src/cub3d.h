/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:36:29 by jcuzin            #+#    #+#             */
/*   Updated: 2024/03/28 23:29:40 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/mlx/mlx.h" 
# include "../lib/mlx/mlx_int.h"
# include "../lib/libft/src/libft.h"
# include "../lib/gnl/src/gnl.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

typedef struct s_player
{
	char		compass;
	long long	xpos;
	long long	ypos;
	int			b_interact;
	int			b_move;
}				t_player;

typedef struct s_map
{
	int			fd;
	char		**map;
	size_t		xlen;
	size_t		ylen;
}				t_map;

typedef struct s_data
{
	int			arg_nb;
	char		**arg_tab;
	t_map		map;
	t_player	player;
}				t_data;

int			db_readfile(char *file);

size_t		err_putstr_fd(char *str, int fd);
int			err_custom(int launch, char *log, char *font);
int			err_stderr(int launch);

int			init_map_struct(t_map *map);
int			init_player_struct(t_player *player);
int			init_data_struct(t_data *data);
int			initset_data_struct(t_data *data, int argc, char **argv);

int			pa_main(t_data *data);
int			pa_checkfile(char *file);

#endif