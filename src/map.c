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

static t_point	*get_points(char **items, int width, int y)
{
	t_point	*line;
	int i;

	line = (t_point *)ft_malloc(width * sizeof(t_point));
	i = 0;
	while (i < width)
	{
		line[i].x = i;
		line[i].y = y;
		line[i]. z = ft_atoi(items[i]);
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
	map->points = (t_point **)ft_malloc(height * sizeof(t_point *));
	y = 0;
	while(y < map->height)
	{
		temp = ft_split(matrix[y], ' ');
		if (y == 0)
		map->width = matrix_item_n(temp);
		map->points[y] = get_points(temp, map->width, y);
		ft_free_matrix(temp);
		y++;
	}
	ft_free_matrix(matrix);
	return ;
}

void	get_map(t_fdf *fdf, char *map_path)
{
	int		fd;
	int		height;
	char	*line;
	char	*map;

	fd = open(map_path, O_RDONLY);
	map = ft_strdup("");
	fdf->map.height = = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line && *line)
			break;
		map = ft_strjoin(map, line);	
		free(line);
		fdf->map.height++;
	}	
	populate_map(&(fdf->map), str);
	close(fd);
	return (0);
}	

matrix = ["2 3 0 0 0", "0 0 0 0 1", "3 0 2 5 0"]
temp = ft_split(matrix[y], ' '); = ["2", "3", "0", "0", "0"]