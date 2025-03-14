/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:40:25 by gangel-a          #+#    #+#             */
/*   Updated: 2025/03/13 21:40:25 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*get_fdf(void)
{
	static t_fdf	fdf;

	return (&fdf);
}

int	matrix_item_n(char **arr)
{
	int		item_n;

	item_n = 0;
	while (arr[item_n])
		item_n++;
	return (item_n);
}