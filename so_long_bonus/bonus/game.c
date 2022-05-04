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

#include "../so_long_b.h"

void	ft_destroy_img(t_program *prog)
{
	mlx_destroy_image(prog->mlx_p, prog->img_cat[0]);
	mlx_destroy_image(prog->mlx_p, prog->img_cat[1]);
	mlx_destroy_image(prog->mlx_p, prog->img_cat[2]);
	mlx_destroy_image(prog->mlx_p, prog->img_cat[3]);
	mlx_destroy_image(prog->mlx_p, prog->img_cat[4]);
	mlx_destroy_image(prog->mlx_p, prog->img_cat[5]);
	mlx_destroy_image(prog->mlx_p, prog->img_cat[6]);
	mlx_destroy_image(prog->mlx_p, prog->img_2);
	mlx_destroy_image(prog->mlx_p, prog->img_3);
	mlx_destroy_image(prog->mlx_p, prog->img_4);
	mlx_destroy_image(prog->mlx_p, prog->img_5);
	mlx_destroy_image(prog->mlx_p, prog->img_6);
	mlx_destroy_image(prog->mlx_p, prog->img_7);
	mlx_destroy_image(prog->mlx_p, prog->img_8);
	mlx_destroy_image(prog->mlx_p, prog->img_9);
	mlx_destroy_image(prog->mlx_p, prog->img_10);
	mlx_destroy_image(prog->mlx_p, prog->img_11);
	mlx_destroy_window(prog->mlx_p, prog->window);
}

int	ft_end_game(t_program *prog)
{
	int	i;

	i = 0;
	ft_destroy_img(prog);
	while (i < prog->w_height)
	{
		free(prog->map[i]);
		i++;
	}
	free(prog->map);
	free(prog->p_y_enemy);
	free(prog->p_x_enemy);
	free(prog);
	exit(1);
	return (0);
}

void	ft_count_enemy(t_program *prog, t_dim *dim)
{
	int	i;
	int	j;
	int	k;

	prog->enemies = 0;
	k = 0;
	i = 0;
	while (i < dim->dim_y)
	{
		j = 0;
		while (j < dim->dim_x)
		{
			if (prog->map[i][j] == 'N')
			{
				prog->enemies++;
				prog->p_y_enemy[k] = i;
				prog->p_x_enemy[k] = j;
				k++;
			}
			j++;
		}
		i++;
	}
}

int	ft_count_food(t_program *prog, t_dim *dim)
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
	return (prog->food);
}

void	ft_start_game(t_program *prog, t_dim *dim)
{
	prog->food = ft_count_food(prog, dim);
	prog->p_y_enemy = (int *)malloc(sizeof(int) * 200);
	prog->p_x_enemy = (int *) malloc(sizeof(int) * 200);
	if (!prog->p_x_enemy || !prog->p_x_enemy)
	{
		ft_print_error(1);
		ft_end_game(prog);
	}
	ft_count_enemy(prog, dim);
	prog->w_height = dim->dim_y;
	prog->w_width = dim->dim_x;
	free(dim);
}
