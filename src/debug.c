/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:57:23 by jcuzin            #+#    #+#             */
/*   Updated: 2024/03/28 23:33:19 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	db_readfile(char *file)
{
	char	*line;
	int		fd;
	size_t	i;

	printf("#\tDB_READFILE\n");
	if (!file)
		return (EXIT_FAILURE);
	i = 0;
	line = NULL;
	printf("\tFile:\t[%s]", file);
	fd = open(file, O_RDONLY);
	if (fd > 2)
		printf("\rOK\n");
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
	return (EXIT_SUCCESS);
}
