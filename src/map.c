/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:41:14 by gangel-a          #+#    #+#             */
/*   Updated: 2025/03/13 21:41:14 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*get_points(char **items, t_map *map, int y)
{
	t_point	*line;
	int		i;

	line = (t_point *)ft_malloc(map->width * sizeof(t_point));
	i = 0;
	while (i < map->width)
	{
		line[i].x = i;
		line[i].y = y;
		line[i].z = ft_atoi(items[i]);
		if (map->max_z < line[i].z)
			map->max_z = line[i].z;
		else if (map->min_z > line[i].z)
			map->min_z = line[i].z;
		line[i].color = get_color(items[i]);
		i++;
	}
	return (line);
}

static void	populate_map(t_map *map, char *str)
{
	char	**matrix;
	char	**temp;
	int		y;

	matrix = ft_split(str, '\n');
	free(str);
	map->points = (t_point **)ft_malloc(map->height * sizeof(t_point *));
	y = 0;
	while (y < map->height)
	{
		temp = ft_split(matrix[y], ' ');
		if (y == 0)
			map->width = matrix_item_n(temp);
		else if (map->width != matrix_item_n(temp))
		{
			ft_free_matrix(temp);
			ft_free_matrix(matrix);
			handle_error(INVALID_MAP);
		}
		map->points[y] = get_points(temp, map, y);
		ft_free_matrix(temp);
		y++;
	}
	ft_free_matrix(matrix);
	return ;
}

void	init_map(t_fdf *fdf, char *map_path)
{
	int		fd;
	char	*line;
	char	*map;

	fd = open(map_path, O_RDONLY);
	map = ft_strdup("");
	fdf->map.height = 0;
	fdf->map.max_z = 0;
	fdf->map.min_z = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line || !*line)
			break ;
		map = ft_strjoin(map, line);
		free(line);
		fdf->map.height++;
	}
	populate_map(&(fdf->map), map);
	close(fd);
	return ;
}
