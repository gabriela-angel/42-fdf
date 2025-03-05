/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:30:39 by gangel-a          #+#    #+#             */
/*   Updated: 2025/03/04 19:00:01 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/include/libft.h"

// MACROS -----------
# define WRONG_USAGE "Error: Wrong format. Try: ./fdf <map>"
# define FDF_ERROR "Error: Not able to initialize fdf."
# define IMG_ERROR "Error: Failed to create image."

// STRUCTS ----------------
typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
}	t_point;

typedef struct s_map
{
	int		height;
	int		width;
	t_point	**map;
}	t_map;

typedef struct s_malloc
{
	void	*list[1000];
	size_t	i;
}	t_malloc;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_fdf;

// COLORS ------------------
# define BLACK 0x000000FF

// INITIALIZATION
t_fdf	*init_fdf(void);

// UTILS -------------------
void	*ft_malloc(size_t size);

// DRAW --------------------
void	draw_background(mlx_image_t *img, int width, int height);

//ERROR --------------------
void	handle_error(char *error_msg);
void	ft_free_all(void);


#endif