/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:12:00 by gangel-a          #+#    #+#             */
/*   Updated: 2025/02/27 20:38:04 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_background(mlx_image_t *img, int width, int height)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < height)
	{
		x = -1;
		while (++x < width)
			mlx_put_pixel(img, x, y, BLACK);
		y++;
	}
}
