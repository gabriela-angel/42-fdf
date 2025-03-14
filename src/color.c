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

uint32_t	get_color(char *str)
{
	char	*color;

	color = ft_strchr(str, ',');
	if(color)
	{
		color++;
		return ((color));
	}
	return (0);
}