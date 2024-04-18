/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:36:29 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/19 01:22:53 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/mlx_linux/mlx.h"
# include "../lib/mlx_linux/mlx_int.h"
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
# define PLUS_KEY			78
# define MINUS_KEY			74
# define UP_ARROW_KEY		65362
# define RIGHT_ARROW_KEY	65363
# define LEFT_ARROW_KEY		65361
# define DOWN_ARROW_KEY		65364
# define TAB_KEY 			65289
# define ESC_KEY 			65307

# define GAME_SCALING		20

# define PLAYER_SPEED		1
# define PLAYER_FOV			110

# define MINIMAP_SCALE		10
# define MINIMAP_POS_X		0
# define MINIMAP_POS_Y		0

typedef struct s_player
{
	char		compass;
	double		angle_rot;
	double		look;
	long long	xpos;
	long long	ypos;
	double		x;
	double		y;
	int			b_touch;
	int			b_move;
	int			move_up;
	int			move_down;
	int			move_right;
	int			move_left;
	int			turn_right;
	int			turn_left;
}				t_player;

typedef struct s_tex
{
	int			life;
	char		*file;
	void		*id;
	int			he;
	int			wi;
	int			lorem;
	int			ipsum;
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

typedef struct s_mlx
{
	void		*init;
	void		*game;
	void		*win;
	int			win_w;
	int			win_h;
	int			win_wmid;
	int			win_hmid;
	double		map_limit[2];
	double		minimap_x;
	double		minimap_y;
	double		minimap_scale;
	double		minimap_angle;
	long		minimap_size[2];
	long		minimap_pos[2];
	double		speed;
	long long	ips;
}				t_mlx;

typedef struct s_data
{
	int			arg_nb;
	char		**arg_tab;
	void		*extra;
	t_map		map;
	t_player	player;
	t_mlx		mlx;
}				t_data;

void		db_ascii_title(char *tab);
void		db_ascii_safemode(char *tab);
void		db_beacon(char *title, long size);
void		db_testft(char *ft_name, int ret_int, char *ret_char);
void		db_showmap(t_map map, int mode);
void		db_showtab(char **tab);
void		db_showplayer(t_player ply);
void		db_keylog(int key);
void		db_game_monitoring(t_data *data);
int			db_framepersecond(void);
int			db_readfile(char *file);
int			db_return(int value, char *log);
void		db_game_info(t_data *data);

int			sb_telecran(t_data *data);
int			sb_movingmap(t_data *data);

size_t		err_putstr_fd(char *str, int fd);
int			err_custom(int launch, char *log, int tab);
int			err_stderr(int launch);
int			err_return(int value, char *log, int level);

int			init_data_struct(t_data *data, int argc, char **argv);
int			init_map_struct(t_map *map, char *file);
int			init_map_texture(t_tex *asset, char **map, char *set, size_t *pos);
int			init_map_trim(t_map *map, char **temp);
int			init_player_struct(t_player *player, t_map map);
int			init_texture_struct(t_data *data, t_tex	*texture);
int			init_mlx_struct(t_data *data);

void		res_tex_struct(t_tex *tex, int free);
void		res_map_struct(t_map *map, int free);
void		res_player_struct(t_player *player, int free);
void		res_data_struct(t_data *data, int free);

int			parse_main(t_data *data);
int			parse_map(t_map map, t_player player);
int			parse_file(char *file);

int			graph_main(t_data *data);
int			graph_close(t_data *data);

int			re_render(t_data *data);
int			re_nothing(void *data);
int			re_draw_image(t_data *data);
void		re_pixeltoimg(t_img *img, int x, int y, int color);

void		draw_square(t_mlx *mlx, size_t size[2], size_t xy[2], int color);
void		draw_square_snap(t_mlx *mlx, size_t one[2], size_t two[2], int color);
void		draw_grid_sq(t_mlx *mlx, size_t size[2], size_t xy[2], int color);
void		draw_grid_tab(t_mlx *mlx, char **tab, int scale, size_t xy[2]);

int			gp_gameplay(t_data *data);
int			gp_move(t_data *data);

int			bind_bindings(int key, t_data *data);
int			bind_keyboard_press(int key, t_data *data);
int			bind_keyboard_release(int key, t_data *data);

int			misc_player_location(t_map map, long long *y, long long *x);
void		misc_opposite_color(int *color);
void		misc_clear_screen(t_img *img);

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

void		mmap_draw_map(t_data *data, size_t area[2], int scale, size_t xy[2]);
int			mmap_move(t_data *data);
int			mmap_minimap(t_data *data);

void		*s_free(char **ptr_memory);
void		*s_malloc(unsigned long size);
void		*s_freetab(char **tab, long i);

char		**conv_file2tab(char *file);
int			conv_rgb(int i[3]);
int			conv_rgbtab(int red, int green, int blue);

void		sf_safemode(t_data data);


#endif
