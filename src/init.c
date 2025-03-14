/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:12:06 by gangel-a          #+#    #+#             */
/*   Updated: 2025/03/13 21:41:43 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*init_fdf(void)
{
	t_fdf	*fdf;

	fdf = get_fdf();
	fdf->mlx = mlx_init(514, 514, "FdF", true);
	if (!fdf->mlx)
		handle_error(FDF_ERROR);
	fdf->img = mlx_new_image(fdf->mlx, 514, 514);
	if (!fdf->img || mlx_image_to_window(fdf->mlx, fdf->img, 0, 0))
	{
		mlx_terminate(fdf->mlx);
		handle_error(IMG_ERROR);
	}
	return (fdf);
}
