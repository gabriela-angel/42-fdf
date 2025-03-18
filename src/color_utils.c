/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:10:33 by gangel-a          #+#    #+#             */
/*   Updated: 2025/03/16 23:10:33 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_red(int color)
{
	return ((color >> 16) & 0xFF);
}

int	get_green(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_blue(int color)
{
	return (color & 0xFF);
}

int	get_alpha(int color)
{
	return ((color >> 24) & 0xFF);
}

int	get_rgba(int red, int green, int blue, int alpha)
{
	return (((alpha) << 24) + ((red) << 16) + ((green) << 8) + (blue));
}
