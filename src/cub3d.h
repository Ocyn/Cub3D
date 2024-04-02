/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:36:29 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/02 23:05:32 by jcuzin           ###   ########.fr       */
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
	double		xpos;
	double		ypos;
	int			b_interact;
	int			b_move;
}				t_player;

typedef struct s_map
{
	int			fd;
	char		**map;
	double		xlen;
	double		ylen;
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

int			init_data_struct(t_data *data, int argc, char **argv);
int			init_map_struct(t_map *map, char *file);
int			init_player_struct(t_player *player);

void		res_map_struct(t_map *map);
void		res_player_struct(t_player *player);
void		res_data_struct(t_data *data);

int			pa_main(t_data *data);
int			pa_checkfile(char *file);

size_t		me_filelen(int fd);
size_t		me_tablen(char **tab);
int			me_strcmp(char *s1, char *s2);
int			me_find_str_in_tab(int strict_mode, char *find, char **tab);
int			me_find_str_in_str(const char *src, const char *seek);

char		**conv_file2tab(int fd);

#endif