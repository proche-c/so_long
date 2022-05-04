/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_b.h"

void	ft_move_enemy_1(t_program *prog, int i, int y, int x)
{
	mlx_put_image_to_window(prog->mlx_p, prog->window,
		prog->img_8, (prog->p_x_enemy[i] + x) * IMG_WIDTH,
		(prog->p_y_enemy[i] + y) * IMG_HEIGHT);
	mlx_put_image_to_window(prog->mlx_p, prog->window,
		prog->img_2, prog->p_x_enemy[i] * IMG_WIDTH,
		prog->p_y_enemy[i] * IMG_HEIGHT);
	prog->map[prog->p_y_enemy[i]][prog->p_x_enemy[i]] = '0';
	prog->map[prog->p_y_enemy[i] + y][prog->p_x_enemy[i] + x] = 'N';
	prog->p_x_enemy[i] = prog->p_x_enemy[i] + x;
	prog->p_y_enemy[i] = prog->p_y_enemy[i] + y;
}

void	ft_move_enemy_2(t_program *prog, int i, int y, int x)
{
	mlx_put_image_to_window(prog->mlx_p, prog->window,
		prog->img_9, (prog->p_x_enemy[i] + x) * IMG_WIDTH,
		(prog->p_y_enemy[i] + y) * IMG_HEIGHT);
	mlx_put_image_to_window(prog->mlx_p, prog->window,
		prog->img_2, prog->p_x_enemy[i] * IMG_WIDTH,
		prog->p_y_enemy[i] * IMG_HEIGHT);
	mlx_put_image_to_window(prog->mlx_p, prog->window, prog->img_10,
		((prog->w_width * IMG_WIDTH / 2)) - 100, 5);
	prog->end = 1;
}
