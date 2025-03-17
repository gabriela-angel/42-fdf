/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:12:00 by gangel-a          #+#    #+#             */
/*   Updated: 2025/03/16 23:30:17 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_background(mlx_image_t *img)
{
	uint32_t	*pixels;
	uint32_t	index;

	pixels = (uint32_t *)img->pixels;
	index = img->height * img->width;
	while (index--)
		pixels[index] = BLACK;
}

static t_isometric	isometric(t_cam *cam, t_point start, t_point end, float rad)
{
	float		x0;
	float		y0;
	float		x1;
	float		y1;
	t_isometric	iso;

	x0 = (start.x - start.y) * cos(rad);
	y0 = (start.x + start.y) * sin(rad);
	iso.start_x = (x0 * cam->tile) + cam->offset_x;
	iso.start_y = (y0 * cam->tile) + cam->offset_y - (start.z * cam->slope);
	x1 = (end.x - end.y) * cos(rad);
	y1 = (end.x + end.y) * sin(rad);
	iso.end_x = (x1 * cam->tile) + cam->offset_x;
	iso.end_y = (y1 * cam->tile) + cam->offset_y - (end.z * cam->slope);
	iso.start_color = start.color;
	iso.end_color = end.color;
	return (iso);
}

static void	set_line(t_fdf *fdf, t_point start, t_point end)
{
	t_isometric	iso;
	float		rad;

	rad = radian(ANGLE);
	if (!start.color)
		start.color = choose_color(fdf->map.max_z, fdf->map.min_z, start.z);
	if (!end.color)
		end.color = choose_color(fdf->map.max_z, fdf->map.min_z, end.z);
	iso = isometric(&(fdf->cam), start, end, rad);
	draw_line(iso, fdf->img);
}

void	draw_map(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	draw_background(fdf->img);
	while (y < fdf->map.height)
	{
		x = -1;
		while (++x < fdf->map.width)
		{
			if (x + 1 < fdf->map.width)
				set_line(fdf, fdf->map.points[y][x], fdf->map.points[y][x + 1]);
			if (y + 1 < fdf->map.height)
				set_line(fdf, fdf->map.points[y][x], fdf->map.points[y + 1][x]);
		}
		y++;
	}
	return ;
}
