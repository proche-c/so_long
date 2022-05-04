/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_initialize_prog(t_program *prog, t_dim *dim)
{
	prog->mlx_p = mlx_init();
	prog->width = dim->dim_x * IMG_WIDTH;
	prog->height = dim->dim_y * IMG_HEIGHT;
	prog->x = IMG_WIDTH;
	prog->y = IMG_HEIGHT;
	prog->width = dim->dim_x * IMG_WIDTH;
	prog->height = dim->dim_y * IMG_HEIGHT;
	prog->move = 0;
	prog->end = 0;
	prog->name = "SUPER KITTY";
	prog->window = mlx_new_window(prog->mlx_p, prog->width,
			prog->height, prog->name);
}

void	ft_initialize_img(t_program *prog)
{
	prog->img_3 = mlx_xpm_file_to_image(prog->mlx_p, PATH_IMG_3,
			&prog->width, &prog->height);
	prog->img_2 = mlx_xpm_file_to_image(prog->mlx_p, PATH_IMG_2,
			&prog->width, &prog->height);
	prog->img_1 = mlx_xpm_file_to_image(prog->mlx_p, PATH_IMG_1,
			&prog->width, &prog->height);
	prog->img_4 = mlx_xpm_file_to_image(prog->mlx_p, PATH_IMG_4,
			&prog->width, &prog->height);
	prog->img_5 = mlx_xpm_file_to_image(prog->mlx_p, PATH_IMG_5,
			&prog->width, &prog->height);
	prog->img_6 = mlx_xpm_file_to_image(prog->mlx_p, PATH_IMG_6,
			&prog->width, &prog->height);
	prog->img_7 = mlx_xpm_file_to_image(prog->mlx_p, PATH_IMG_7,
			&prog->width, &prog->height);
}
