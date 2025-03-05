/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:58:58 by gangel-a          #+#    #+#             */
/*   Updated: 2025/03/04 18:58:58 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import "fdf.h"

void    read_map(char *map_path)
{
	int		fd;
	int		height;
	char	*line;
	char	*map;

	fd = open(map_path, O_RDONLY);
	map = ft_strdup("");
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line && *line)
			break;
		map = ft_strjoin(map, line);
		free(line);
		height++;
	}
	populate_map(map, height);
	close(fd);
	return (0);
}

char	**get_line(char *arr)
{
	char	*temp;
	char	**line;

	temp = ft_strtrim(arr, "/n");
	line = ft_split(temp, ' ');
	free(temp);
	return (line);
}

int	array_item_n(char **arr)
{
	int		item_n;

	item_n = 0;
	while (arr[item_n])
		item_n++;
	return (item_n);
}

void	populate_map(char *str, int height)
{
	t_fdf	*fdf;
	char	**matrix;
	int		y;
	
	fdf = get_fdf();
	fdf->map.height = height;
	matrix = ft_split(str, '\n');
	free(str);
	fdf->map.map = (t_point **)ft_malloc(height * sizeof(t_point *));
	y = 0;
	while(y < height)
	{
		temp = get_line(matrix[y]);
		if (y == 0)
			fdf->map.width = array_item_n(temp);
		//
		fdf->map.map[y] = get_point(temp, y);
		ft_free_matrix(temp);
		y++;
	}
	ft_free_matrix(matrix);
	return ;
}

matrix = ["2 3 0 0 0\n", "0 0 0 0 1\n", "3 0 2 5 0\n"]
temp = ft_split(matrix[y], ' '); = ["2", "3", "0", "0", "0"]