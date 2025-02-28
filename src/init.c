/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:12:06 by gangel-a          #+#    #+#             */
/*   Updated: 2025/02/28 15:17:11 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*init_fdf(void)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
	{
		// Handle memory allocation failure
		return ((t_fdf *) NULL);
	}
	fdf->mlx = mlx_init(514, 514, "FdF", true);
	if (!fdf->mlx)
	{
		//ft_printf("Error: MLX initialization failed.\n");
		return ((t_fdf *) NULL);
	}
	fdf->img = mlx_new_image(fdf->mlx, 514, 514);
	if (!fdf->img || mlx_image_to_window(fdf->mlx, fdf->img, 0, 0))
	{
		mlx_terminate(fdf->mlx);
		free(fdf);
		//ft_printf("Error: Failed to create image.\n");
		return ((t_fdf *) NULL);
	}
	return (fdf);
}
