/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:35:46 by gangel-a          #+#    #+#             */
/*   Updated: 2025/02/26 17:46:57 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	mlx_t	*mlx_pointer;

	mlx_pointer = mlx_init(514, 514, "test fdf", true);
	//if (!mlx_pointer)
	//{
	//	free stuff
	//}
	mlx_loop(mlx_pointer);
}
