/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:40:25 by gangel-a          #+#    #+#             */
/*   Updated: 2025/03/13 21:40:25 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*get_fdf(void)
{
	static t_fdf	fdf;

	return (&fdf);
}

int	matrix_item_n(char **arr)
{
	int		item_n;

	if (!arr)
		return (0);
	item_n = 0;
	while (arr[item_n])
		item_n++;
	return (item_n);
}

float	radian(float degree)
{
	return ((degree * M_PI) / 180.0);
}

void	validate_map(char *map_path)
{
	char	*line;
	int		fd;

	if (ft_strncmp(map_path + ft_strlen(map_path) - 4, ".fdf", 4) != 0)
		handle_error(INVALID_MAP);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		handle_error(INVALID_MAP);
	}
	line = get_next_line(fd);
	if (!line || line[0] == '\0' || line[0] == '\n' || line[0] == '\r')
	{
		close(fd);
		free(line);
		get_next_line(-42);
		handle_error(EMPTY_MAP);
	}
	free(line);
	get_next_line(-42);
	close(fd);
}
