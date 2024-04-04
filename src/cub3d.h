/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:36:29 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/04 21:33:14 by jcuzin           ###   ########.fr       */
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

# define F_DEFAULT		"\033[0m"
# define F_UNDERLINE	"\033[4m"
# define F_BOLD			"\033[1m"
# define F_REVERSE		"\033[2m"
# define F_BLACK		"\033[0;30m"
# define F_WHITE		"\033[0;15m"
# define F_DGREY		"\033[0;100m"
# define F_RED			"\033[0;91m"
# define F_GREEN		"\033[0;92m"
# define F_YELLOW		"\033[0;93m"
# define F_BLUE			"\033[0;94m"
# define F_PURPLE		"\033[0;35m"
# define F_CYAN			"\033[0;96m"
# define F_LGREY		"\033[0;37m"
# define F_DRED			"\033[38;5;160m"
# define F_BLACK2		"\033[38;5;235m"
# define F_BLACK3		"\033[38;5;16m"
# define F_LGREY2		"\033[38;5;248m"
# define F_RED2			"\033[38;5;1m"

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

void		db_ascii_title(char *tab);
void		db_ascii_dbmode(char *tab);
void		db_testft(char *ft_name, int ret_int, char *ret_char);
int			db_readfile(char *file);
int			db_return(int value, char *log);
void		db_showmap(t_map map);

size_t		err_putstr_fd(char *str, int fd);
int			err_custom(int launch, char *log, int tab);
int			err_stderr(int launch);

int			init_data_struct(t_data *data, int argc, char **argv);
int			init_map_struct(t_map *map, char *file);
int			init_player_struct(t_player *player);

void		res_map_struct(t_map *map);
void		res_player_struct(t_player *player);
void		res_data_struct(t_data *data);

int			parse_main(t_data *data);
int			parse_map(t_map *map);
int			parse_file(char *file);

void		me_free_tab(char **tab, int i);
size_t		me_filelen(char *file);
size_t		me_tablen(char **tab);
size_t		me_strchrn(char *src, char seek);
int			me_strcmp(char *s1, char *s2);
int			me_str2strcmp(char *src, char *reg);
int			me_find_str_in_tab(int strict_mode, char *find, char **tab);
int			me_find_str_in_str(const char *src, const char *seek);

void		s_free(char **ptr_memory);
void		*s_malloc(unsigned long size);

char		**conv_file2tab(char *file);

#endif