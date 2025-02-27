/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:35:46 by gangel-a          #+#    #+#             */
/*   Updated: 2025/02/27 20:40:16 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_window(void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	main(int argc, char **argv)
{
	mlx_t		*mlx_pointer;
	mlx_image_t	*img;

	(void) argc;
	(void) argv;

	//if (argc != 2)
	//{
	//	ft_printf("Error: Wrong format.\n");
	//	ft_printf("Program executed as: ./fdf <map_path>\n");
	//	return (1);
	//}

	mlx_pointer = mlx_init(514, 514, "test fdf", true);
	//if (!mlx_pointer)
	//{
	//	free stuff
	//}
	img = mlx_new_image(mlx_pointer, 514, 514);
	//if (!img)
	//{
	//	free stuff
	//}
	draw_background(img, 514, 514);
	mlx_loop_hook(mlx_pointer, close_window, mlx_pointer);
	mlx_loop(mlx_pointer);
}
