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

static unsigned int	ft_htoi(char *hex)
{
	unsigned int	final_int;
	int	num;
	int	i;

	i = -1;
	final_int = 0;
	if (hex[0] == '#') {
		hex++;
	} else if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
		hex += 2;
	}
	while (hex[++i] && hex[i] != ' ' && hex[i] != '\n')
	{
		num = hex[i];
		if (num >= '0' && num <= '9')
			num = num - '0';
		else if (num >= 'a' && num <= 'f')
			num = num - 'a' + 10;
		else if (num >= 'A' && num <= 'F')
			num = num - 'A' + 10;
		else
			handle_error(INVALID_COLOR);
		final_int = (final_int * 16) + num;
	}
	return (final_int);
}

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

	hex = ft_strchr(str, ',');
	if(hex)
	{
		hex++;
		return (put_alpha(ft_htoi(hex)));
	}
	return (0);
}