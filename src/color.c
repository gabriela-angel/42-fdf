/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:30:45 by gangel-a          #+#    #+#             */
/*   Updated: 2025/03/13 22:30:45 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static uint32_t	put_alpha(uint32_t color)
{
	uint32_t		rgba;
	unsigned char	*ptr;

	rgba = color << 8;
	ptr = (unsigned char *)&rgba;
	*ptr = 0xFF;
	return (rgba);
}

uint32_t	get_color(char *str)
{
	char	*hex;
	int		color;

	hex = ft_strchr(str, ',');
	if (hex)
	{
		hex++;
		color = ft_htoi(hex);
		if (color < 0)
			handle_error(INVALID_COLOR);
		return (put_alpha(color));
	}
	return (0);
}

uint32_t	choose_color(int max_z, int min_z, int current_z)
{
	if (current_z == 0)
		return (WHITE);
	if (max_z > 0)
	{
		if (current_z == max_z / 2)
			return (PINK);
		if (current_z == max_z)
			return (BLUE);
		if (current_z > 0 && current_z < max_z / 2)
			return (gradient(PINK, WHITE, max_z / 2, max_z / 2 - current_z));
		if (current_z > max_z / 2 && current_z < max_z)
			return (gradient(BLUE, PINK, max_z / 2, max_z - current_z));
	}
	if (min_z < 0)
	{
		if (current_z == min_z)
			return (PURPLE);
		if (current_z == min_z / 2)
			return (ORANGE);
		if (current_z > min_z && current_z < min_z / 2)
			return (gradient(PURPLE, ORANGE, -min_z / 2, current_z - min_z));
		if (current_z > min_z / 2 && current_z < 0)
			return (gradient(ORANGE, WHITE, -min_z / 2, current_z - min_z / 2));
	}
	return (0);
}

uint32_t	gradient(int start_color, int end_color, int grad_len, int position)
{
	double	increment[4];
	int		new[4];
	int		new_color;

	increment[0] = (double)(get_red(end_color) - get_red(start_color))
		/ (double)grad_len;
	increment[1] = (double)(get_green(end_color) - get_green(start_color))
		/ (double)grad_len;
	increment[2] = (double)(get_blue(end_color) - get_blue(start_color))
		/ (double)grad_len;
	increment[3] = (double)(get_alpha(end_color) - get_alpha(start_color))
		/ (double)grad_len;
	new[0] = get_red(start_color) + round(increment[0] * position);
	new[1] = get_green(start_color) + round(increment[1] * position);
	new[2] = get_blue(start_color) + round(increment[2] * position);
	new[3] = get_alpha(start_color) + round(increment[3] * position);
	new_color = get_rgba(new[0], new[1], new[2], new[3]);
	return (new_color);
}
