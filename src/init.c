/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:12:06 by gangel-a          #+#    #+#             */
/*   Updated: 2025/02/28 20:28:29 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf	*get_fdf(void)
{
	static int	fdf;

	return (&fdf);
}

t_fdf	*init_fdf(void)
{
	t_fdf	fdf;

	fdf.img

	fdf = get_fdf();
	fdf->mlx = mlx_init(514, 514, "FdF", true);
	if (!fdf->mlx)
	{
		fdf = ft_malloc(sizeof(t_fdf));
		if (!fdf)
			handle_error(FDF_ERROR);
		ft_printf("Error: MLX initialization failed.\n");
		return ((t_fdf *) NULL);
	}
	fdf->img = mlx_new_image(fdf->mlx, 514, 514);
	if (!fdf->img || mlx_image_to_window(fdf->mlx, fdf->img, 0, 0))
	{
		mlx_terminate(fdf->mlx);
		handle_error(IMG_ERROR);
	}
	return (fdf);
}
