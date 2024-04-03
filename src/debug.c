/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:57:23 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/03 23:28:52 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	db_ascii_title(char *tab)
{
	printf("%s\n", F_DEFAULT);
	printf("%s_________________________________________\n\n", tab);
	printf("%s%s ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ \n", tab, F_LGREY2);
	printf("%s%s██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗\n", tab, F_WHITE);
	printf("%s%s██║     ██║   ██║██████╔╝ █████╔╝██║  ██║\n", tab, F_BLACK3);
	printf("%s%s██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║\n", tab, F_DRED);
	printf("%s%s╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝\n", tab, F_RED2);
	printf("%s%s ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ \n", tab, F_WHITE);
	printf("%s%s          By Jcuzin x Aammirat          \n", tab, F_BOLD);
	printf("%s%s_________________________________________\n", tab, F_WHITE);
	printf("%s\n", F_DEFAULT);
}

void	db_ascii_dbmode(char *tab)
{
	printf("%s\n", F_DEFAULT);
	printf("%s%s┳┓┏┓┳┓┳┳┏┓  ┳┳┓┏┓┳┓┏┓\n", tab, F_DEFAULT);
	printf("%s%s┃┃┣ ┣┫┃┃┃┓  ┃┃┃┃┃┃┃┣\n", tab, F_DEFAULT);
	printf("%s%s┻┛┗┛┻┛┗┛┗┛  ┛ ┗┗┛┻┛┗┛\n", tab, F_DEFAULT);
	printf("%s\n", F_DEFAULT);
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
