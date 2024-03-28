/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:36:29 by jcuzin            #+#    #+#             */
/*   Updated: 2024/03/28 18:07:44 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/mlx/mlx.h"
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
	t_map		*map;
	t_player	*player;
}				t_data;

int			db_readfile(char *file);

#endif