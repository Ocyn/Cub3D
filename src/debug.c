/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:57:23 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/23 18:57:03 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <time.h> //Librarie temporaire

void	db_ascii_title(char *tab)
{
	printf("%s\n", F_DEFAULT);
	printf("%s_________________________________________\n\n", tab);
	printf("%s%s ██████ ██    ██ ██████  ██████╗ ██████╗ \n", tab, F_LGREY2);
	printf("%s%s██      ██    ██ ██   ██ ╚════██╗██╔══██╗\n", tab, F_WHITE);
	printf("%s%s██      ██    ██ █████    █████╔╝██║  ██║\n", tab, F_BLACK);
	printf("%s%s██      ██    ██ ██   ██  ╚═══██╗██║  ██║\n", tab, F_DRED);
	printf("%s%s ██████  ██████  ██████  ██████╔╝██████╔╝\n", tab, F_RED2);
	printf("%s%s                         ╚═════╝ ╚═════╝ \n", tab, F_WHITE);
	printf("%s%s          By Jcuzin x Aammirat          \n", tab, F_BOLD);
	printf("%s%s_________________________________________\n", tab, F_WHITE);
	printf("%s\n", F_DEFAULT);
}

void	db_ascii_safemode(char *tab)
{
	printf("%s\n", F_DEFAULT);
	printf("%s%ssaf mud\n", tab, F_DEFAULT);
	printf("%s\n", F_DEFAULT);
}

void	db_beacon(char *title, long size)
{
	long	len;
	long	id;

	id = 0;
	len = ft_strlen(title);
	printf("%s\n", F_BOLD);
	while (++id < (size - len) / 2)
		printf("#");
	printf(" %s ", title);
	while (--id > 0)
		printf("#");
	printf("%s\n", F_DEFAULT);
}

void	db_key_event(int key)
{
	printf(" Key [%d]\n", key);
}

void	db_game_info(t_data *data)
{
	printf("\nScreen\t\tW[%d] H[%d]\n", data->mlx.win_w, data->mlx.win_h);
	printf("InGame Data:\n");
	printf(" Map Scale:\t\t[%d]:[X:%.1f][Y:%.1f]\n", GAME_SCALING, data->mlx.map_limit[0], data->mlx.map_limit[1]);
	printf(" Speed:\t\t3D[%.2f] | Minimap[%.2f]\n", data->mlx.speed, data->mlx.speed);
	printf("\n\n");
}

void	db_game_monitoring(t_data *data)
{
	long		pmapx;
	long		pmapy;
	t_player	*player;
	t_mlx		*mlx;

	data->mlx.ips++;
	player = &data->player;
	mlx = &data->mlx;
	pmapx = data->mlx.win_w;
	pmapy = data->mlx.win_h;
	printf("\rFPS [%d]", db_framepersecond());
	printf(" | Scale[%.1f]", mlx->game_scale);
	printf(" | Player[%.2f][%.2f].[%.2f]", player->x, player->y, player->angle_rot);
	printf(" | Mouse[X:%d][Y:%d]", data->mlx.mouse_pos[0], data->mlx.mouse_pos[1]);
	//printf(" | Map[%.2f][%.2f]", mlx->minimap_x, mlx->minimap_y);
	printf("      \r");
}

void	db_mouse(int key, t_data data)
{
	t_mlx	mlx;

	mlx = data.mlx;
	printf("\nDB_MOUSE \n");
	printf("\tKey [%d]\n", key);
	printf("\tPosition [%d][%d]\n", mlx.mouse_pos[0], mlx.mouse_pos[1]);
}

int	db_framepersecond(void)
{
	static long long	previous_time;
	long long			current_time = clock();

	if (!previous_time)
	{
		previous_time = current_time;
		current_time = clock();
	}
	int	fps = CLOCKS_PER_SEC / (current_time - previous_time);
	previous_time = current_time;
	return (fps);
}

void	db_testft(char *ft_name, int ret_int, char *ret_char)
{
	if (!ft_name)
		return ;
	printf("# DB_TESTFT: [%s]\n", ft_name);
	printf("\tINT - [%d]\n", ret_int);
	if (ret_char)
		printf("\tSTR - [%s]\n", ret_char);
}

int	db_return(int value, char *log)
{
	if (value)
		printf("\n%sError\n%s%s\n", "\033[4m\033[1;91m", F_DEFAULT, log);
	else
		printf("\t%sOK%s\n", F_GREEN, F_DEFAULT);
	return (value);
}

static void	db_showtexturebis(int *tex, char *id)
{
	if (!tex)
		return ;
	printf("%sTexture %s%s\n", F_UNDERLINE, id, F_DEFAULT);
	printf("RGB\t[%d]", tex[0]);
	printf("[%d]", tex[1]);
	printf("[%d]", tex[2]);
	printf("\n\n");
}

void	db_keylog(int key)
{
	if (key == ESC_KEY)
		printf("Escape\t\t[%d]\n", key);
	if (key == A_KEY || key == Q_KEY || key == LEFT_ARROW_KEY)
		printf("Left\t\t[%d]\n", key);
	if (key == D_KEY || key == RIGHT_ARROW_KEY)
		printf("Right\t\t[%d]\n", key);
	if (key == Z_KEY || key == W_KEY || key == UP_ARROW_KEY)
		printf("Forward\t\t[%d]\n", key);
	if (key == S_KEY || key == DOWN_ARROW_KEY)
		printf("Backward\t\t[%d]\n", key);
	if (key == TAB_KEY)
		printf("Tab\t\t[%d]\n", key);
}

static void	db_showtexture(t_tex tex, char *id)
{
	printf("%sTexture %s%s\n", F_UNDERLINE, id, F_DEFAULT);
	printf("file\t[%s]\n", tex.file);
	if (tex.life)
	{
		printf("mlx id\t[%p]\n", tex.id);
		printf("size\t[%d][%d]\n", tex.wi, tex.he);
	}
	//printf("lorem\t[%d]\n", tex.lorem);
	printf("\n");
}

void	db_showtab(char **tab)
{
	size_t	my;

	my = 0;
	db_beacon("DB_SHOWTAB", 42);
	while (tab[my])
	{
		printf("%ld\t|%s|\n", my + 1, tab[my]);
		my++;
	}
	printf("\n\n");
}

void	db_showplayer(t_player ply)
{
	db_beacon("DB_SHOWPLAYER", 42);
	printf("\n");
	printf("Compass\t[%c]\n", ply.compass);
	printf("X / Y\t[%lld][%lld]\n", ply.xpos, ply.ypos);
	printf("B_touch\t[%d]\n", ply.b_touch);
	printf("B_move\t[%d]\n", ply.b_move);
	printf("\n");
}

void	db_showmap(t_map map, int mode)
{
	size_t	my;

	my = 0;
	db_beacon("DB_SHOWMAP", 42);
	if (!mode || mode == 1)
	{
		printf("\n%s# Properties%s\n\n", F_BOLD, F_DEFAULT);
		db_showtexture(map.tex_no, "North");
		db_showtexture(map.tex_so, "South");
		db_showtexture(map.tex_ea, "East");
		db_showtexture(map.tex_we, "West");
		db_showtexturebis(map.floor, "Floor");
		db_showtexturebis(map.roof, "Roof");
	}
	if (!mode || mode == 2)
	{
		printf("\n%s# Format%s (Y/X: %lld/%lld)\n\n", F_BOLD, F_DEFAULT, map.ylen, map.xlen);
		while ((long long)my <= map.ylen)
		{
			printf("%ld\t|%s|\n", my + 1, map.map[my]);
			my++;
		}
	}
	printf("\n\n");
}

int	db_readfile(char *file)
{
	char	*line;
	int		fd;
	size_t	i;

	printf("# DB_READFILE\n");
	if (!file)
		return (EXIT_FAILURE);
	i = 0;
	line = NULL;
	printf("\tFile:\t[%s]", file);
	fd = open(file, O_RDONLY);
	if (fd > 2)
		printf("\nOK\n%s####SOF%s\n", "\033[1m", "\033[0m");
	else
		printf("\rKO\n");
	while (fd > 2)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (i % 2 == 1)
			printf("%s%s%s", "\033[0;92m", line, "\033[0m");
		else
			printf("%s%s%s", "\033[0;96m", line, "\033[0m");
		free(line);
		i++;
	}
	close(fd);
	printf("\n%s####EOF%s\n\n", "\033[1m", "\033[0m");
	return (EXIT_SUCCESS);
}
