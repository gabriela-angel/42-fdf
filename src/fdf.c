/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:35:46 by gangel-a          #+#    #+#             */
/*   Updated: 2025/02/28 19:31:37 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	printf("Key %d pressed with action %d\n", keydata.os_key, keydata.action);
	if (keydata.os_key == 9 && keydata.action == MLX_PRESS)
		mlx_close_window(fdf->mlx);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	(void) argc;
	(void) argv;

	//if (argc != 2)
	//	handle_error (WRONG_USAGE);
	fdf = init_fdf();

	draw_background(fdf->img, 514, 514);
	mlx_key_hook(fdf->mlx, handle_key, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	ft_free_all();
}
