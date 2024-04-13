/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:36:29 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/13 05:12:36 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/mlx_linux/mlx.h" 
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

# define W_KEY				119
# define A_KEY				97
# define S_KEY				115
# define D_KEY				100
# define Z_KEY				122
# define Q_KEY				113
# define UP_ARROW_KEY		65362
# define RIGHT_ARROW_KEY	65363
# define LEFT_ARROW_KEY		65361
# define DOWN_ARROW_KEY		65364
# define TAB_KEY 			65289
# define ESC_KEY 			65307

# define WIN_HEIGHT			1800
# define WIN_WIDTH			3200

typedef struct s_player
{
	char		compass;
	long long	xpos;
	long long	ypos;
	int			b_touch;
	int			b_move;
}				t_player;

typedef struct s_tex
{
	int			fd;
	char		*file;
	void		*id;
	int			xlen;
	int			ylen;
	int			lorem;
}				t_tex;

typedef struct s_map
{
	char		**map;
	char		**map_bis;
	t_tex		tex_no;
	t_tex		tex_so;
	t_tex		tex_ea;
	t_tex		tex_we;
	int			floor[3];
	int			roof[3];
	long long	xlen;
	long long	ylen;
}				t_map;

typedef struct s_data
{
	int			arg_nb;
	char		**arg_tab;
	void		*mlxinit;
	void		*win;
	void		*extra;
	int			win_w;
	int			win_h;
	int			win_w_center;
	int			win_h_center;
	t_map		map;
	t_player	player;
}				t_data;

void		db_ascii_title(char *tab);
void		db_ascii_safemode(char *tab);
void		db_beacon(char *title, long size);
void		db_testft(char *ft_name, int ret_int, char *ret_char);
int			db_readfile(char *file);
int			db_return(int value, char *log);
void		db_showmap(t_map map, int mode);
void		db_showtab(char **tab);
void		db_showplayer(t_player ply);

size_t		err_putstr_fd(char *str, int fd);
int			err_custom(int launch, char *log, int tab);
int			err_stderr(int launch);
int			err_return(int value, char *log, int level);

int			init_data_struct(t_data *data, int argc, char **argv);
int			init_map_struct(t_map *map, char *file);
int			init_map_texture(t_tex *asset, char **map, char *set, size_t *pos);
int			init_map_trim(t_map *map, char **temp);
int			init_player_struct(t_player *player, t_map map);

void		res_tex_struct(t_tex *tex, int free);
void		res_map_struct(t_map *map, int free);
void		res_player_struct(t_player *player, int free);
void		res_data_struct(t_data *data, int free);

int			parse_main(t_data *data);
int			parse_map(t_map map, t_player player);
int			parse_file(char *file);

int			graph_main(t_data *data);
int			graph_close(t_data *data);

int			gp_gameplay(int key, t_data *data);

int			misc_player_location(t_map map, long long *y, long long *x);

char		**me_tabdup(char **src, size_t src_len);
char		**me_tabdup_ratio(char **src, long long src_len);
void		me_insert_tab_in_tab(char **insert, char ***tab, long where);
void		me_str_edit(char **src, char *seek, char *replace);
void		me_set_color(int *src, size_t red, size_t green, size_t blue);
size_t		me_filelen(char *file);
size_t		me_tablen(char **tab);
size_t		me_strchrn(char *src, char seek);
void		me_diffusion(char **tab, long my, long mx, char limit);
int			me_strcmp(char *s1, char *s2);
int			me_strcat(char *dest, char *src);
int			me_str2strcmp(char *src, char *reg);
int			me_find_str_in_tab(int strict_mode, char *find, char **tab);
int			me_find_str_in_str(const char *src, const char *seek);

void		*s_free(char **ptr_memory);
void		*s_malloc(unsigned long size);
void		*s_freetab(char **tab, long i);

char		**conv_file2tab(char *file);

void		sf_safemode(t_data data);

#endif