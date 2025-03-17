/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:50:21 by gangel-a          #+#    #+#             */
/*   Updated: 2025/03/15 18:17:07 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_error(char *error_msg)
{
	t_fdf	*fdf;

	fdf = get_fdf();
	if (fdf->mlx)
		mlx_terminate(fdf->mlx);
	ft_free_all();
	ft_printf("%s\n", error_msg);
	exit(1);
}
