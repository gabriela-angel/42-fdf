/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:12:06 by gangel-a          #+#    #+#             */
/*   Updated: 2025/03/16 22:07:40 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	tile_size(t_map *map)
{
	float	tile_x;
	float	tile_y;

	tile_x = WIDTH / map->width;
	tile_y = HEIGHT / map->height;
	if (tile_x < tile_y && tile_x > 2)
		return (tile_x * 0.5);
	if (tile_y > 2)
		return (tile_y * 0.5);
	return (1);
}

static float	slope_factor(t_map *map)
{
	if (map->max_z <= 20)
		return (10);
	else if (map->max_z > 720)
		return (0.2);
	else
		return (1);
}

static void	init_cam(t_fdf *fdf)
{
	float	map_offset_x;
	float	map_offset_y;

	fdf->cam.tile = tile_size(&(fdf->map));
	map_offset_x = (fdf->map.width - fdf->map.height) * fdf->cam.tile / 2;
	map_offset_y = (fdf->map.height + fdf->map.width) * fdf->cam.tile / 4;
	fdf->cam.offset_x = WIDTH / 2 - map_offset_x;
	fdf->cam.offset_y = HEIGHT / 2 - map_offset_y;
	fdf->cam.slope = slope_factor(&(fdf->map));
}

void	init_fdf(char *map_path)
{
	t_fdf	*fdf;

	fdf = get_fdf();
	init_map(fdf, map_path);
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!fdf->mlx)
		handle_error(FDF_ERROR);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img || mlx_image_to_window(fdf->mlx, fdf->img, 0, 0))
		handle_error(IMG_ERROR);
	init_cam(fdf);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	return ;
}
