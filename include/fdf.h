/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:30:39 by gangel-a          #+#    #+#             */
/*   Updated: 2025/03/16 23:41:06 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/include/libft.h"

# define WIDTH 1600
# define HEIGHT 900
# define ANGLE 30

// ERROR MACROS -----------
# define WRONG_USAGE "Error: Wrong format. Try: ./fdf <map>"
# define INVALID_MAP "Error: Invalid map."
# define EMPTY_MAP "Error: Map is empty."
# define INVALID_COLOR "Error: Invalid color."
# define FDF_ERROR "Error: Not able to initialize fdf."
# define IMG_ERROR "Error: Failed to create image."

// COLOR MACROS ------------------
# define BLACK 0xFF000000
# define WHITE 0xFFFFFFFF
# define PURPLE 0X800080FF  // Purple
# define ORANGE 0XFF8C00FF  // Dark Orange
# define PINK 0XFF69B4FF  // Pink
# define BLUE 0X00B7EBFF  // Light Blue

// STRUCTS ----------------
typedef struct s_draw
{
	int	diff_x;
	int	diff_y;
	int	desloc_x;
	int	desloc_y;
	int	x;
	int	y;
}	t_draw;

typedef struct s_isometric
{
	int			start_x;
	int			start_y;
	int			end_x;
	int			end_y;
	uint32_t	start_color;
	uint32_t	end_color;
}	t_isometric;

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
	float	max_z;
	float	min_z;
	t_point	**points;
}	t_map;

typedef struct s_cam
{
	float	tile;
	float	offset_x;
	float	offset_y;	
	float	slope;
}	t_cam;

typedef struct s_malloc
{
	void	*list[1000];
	size_t	i;
}	t_malloc;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		map;
	t_cam		cam;
}	t_fdf;

// INITIALIZATION ----------------
void		init_fdf(char *map_path);
void		init_map(t_fdf *fdf, char *map_path);

// COLORS ------------------
uint32_t	get_color(char *str);
uint32_t	choose_color(int max_z, int min_z, int current_z);
uint32_t	gradient(int start_color, int end_color, int grad_len, int position);
int			get_red(int color);
int			get_green(int color);
int			get_blue(int color);
int			get_alpha(int color);
int			get_rgba(int red, int green, int blue, int alpha);

// DRAW --------------------
void		draw_map(t_fdf *fdf);
void		draw_line(t_isometric iso, mlx_image_t *img);

// UTILS -------------------
t_fdf		*get_fdf(void);
int			matrix_item_n(char **arr);
float		radian(float degree);
void		validate_map(char *map_path);

//ERROR --------------------
void		handle_error(char *error_msg);

//FT_MALLOC -----------------
void		*ft_malloc(size_t size);
void		ft_free_all(void);

#endif