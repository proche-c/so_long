/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_end_game(t_program *prog)
{
	int	i;

	i = 0;
	mlx_destroy_image(prog->mlx_p, prog->img_1);
	mlx_destroy_image(prog->mlx_p, prog->img_2);
	mlx_destroy_image(prog->mlx_p, prog->img_3);
	mlx_destroy_image(prog->mlx_p, prog->img_4);
	mlx_destroy_image(prog->mlx_p, prog->img_5);
	mlx_destroy_image(prog->mlx_p, prog->img_6);
	mlx_destroy_image(prog->mlx_p, prog->img_7);
	mlx_destroy_window(prog->mlx_p, prog->window);
	while (i < prog->w_height)
	{
		free(prog->map[i]);
		i++;
	}
	free(prog->map);
	free(prog);
	exit(1);
	return (0);
}

void	ft_start_game(t_program *prog, t_dim *dim)
{
	int	i;
	int	j;

	prog->food = 0;
	i = 0;
	while (i < dim->dim_y)
	{
		j = 0;
		while (prog->map[i][j] != '\0')
		{
			if (prog->map[i][j] == 'C')
				prog->food++;
			j++;
		}
		i++;
	}
	prog->w_height = dim->dim_y;
	prog->w_width = dim->dim_x;
	free(dim);
}
