/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:04:27 by gangel-a          #+#    #+#             */
/*   Updated: 2025/03/16 21:04:27 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_horizontal(t_isometric iso, t_draw line, mlx_image_t *img)
{
	int			diff;
	uint32_t	color;

	diff = line.diff_x / 2;
	while (line.x != iso.end_x)
	{
		color = gradient(iso.start_color, iso.end_color,
				line.diff_x, ft_num_abs(line.x - iso.start_x));
		mlx_put_pixel(img, line.x, line.y, color);
		diff -= line.diff_y;
		if (diff < 0)
		{
			line.y += line.desloc_y;
			diff += line.diff_x;
		}
		line.x += line.desloc_x;
	}
}

static void	draw_vertical(t_isometric iso, t_draw line, mlx_image_t *img)
{
	int			diff;
	uint32_t	color;

	diff = line.diff_y / 2;
	while (line.y != iso.end_y)
	{
		color = gradient(iso.start_color, iso.end_color,
				line.diff_y, ft_num_abs(line.y - iso.start_y));
		mlx_put_pixel(img, line.x, line.y, color);
		diff -= line.diff_x;
		if (diff < 0)
		{
			line.x += line.desloc_x;
			diff += line.diff_y;
		}
		line.y += line.desloc_y;
	}
}

void	draw_line(t_isometric iso, mlx_image_t *img)
{
	t_draw	line;

	line.diff_x = ft_num_abs(iso.end_x - iso.start_x);
	line.diff_y = ft_num_abs(iso.end_y - iso.start_y);
	line.desloc_x = -1;
	if (iso.start_x < iso.end_x)
		line.desloc_x = 1;
	line.desloc_y = -1;
	if (iso.start_y < iso.end_y)
		line.desloc_y = 1;
	line.x = iso.start_x;
	line.y = iso.start_y;
	if (line.diff_x > line.diff_y)
		draw_horizontal(iso, line, img);
	else
		draw_vertical(iso, line, img);
	return ;
}
