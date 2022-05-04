/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_b.h"

void	ft_anim_cat_r(t_program *prog)
{
	if (prog->anim == 7 * ANIM)
		mlx_put_image_to_window(prog->mlx_p, prog->window,
			prog->img_cat[5], prog->p_x * IMG_WIDTH, prog->p_y * IMG_HEIGHT);
	else if (prog->anim == 8 * ANIM)
		mlx_put_image_to_window(prog->mlx_p, prog->window,
			prog->img_cat[4], prog->p_x * IMG_WIDTH, prog->p_y * IMG_HEIGHT);
	else if (prog->anim == 9 * ANIM)
		mlx_put_image_to_window(prog->mlx_p, prog->window,
			prog->img_cat[3], prog->p_x * IMG_WIDTH, prog->p_y * IMG_HEIGHT);
	else if (prog->anim == 10 * ANIM)
		mlx_put_image_to_window(prog->mlx_p, prog->window,
			prog->img_cat[2], prog->p_x * IMG_WIDTH, prog->p_y * IMG_HEIGHT);
	else if (prog->anim == 11 * ANIM)
		mlx_put_image_to_window(prog->mlx_p, prog->window,
			prog->img_cat[1], prog->p_x * IMG_WIDTH, prog->p_y * IMG_HEIGHT);
	else if (prog->anim == 12 * ANIM)
	{
		mlx_put_image_to_window(prog->mlx_p, prog->window,
			prog->img_cat[0], prog->p_x * IMG_WIDTH, prog->p_y * IMG_HEIGHT);
		prog->anim = 0;
	}
}

void	ft_anim_cat(t_program *prog)
{
	if (prog->anim == ANIM)
		mlx_put_image_to_window(prog->mlx_p, prog->window,
			prog->img_cat[1], prog->p_x * IMG_WIDTH, prog->p_y * IMG_HEIGHT);
	else if (prog->anim == 2 * ANIM)
		mlx_put_image_to_window(prog->mlx_p, prog->window,
			prog->img_cat[2], prog->p_x * IMG_WIDTH, prog->p_y * IMG_HEIGHT);
	else if (prog->anim == 3 * ANIM)
		mlx_put_image_to_window(prog->mlx_p, prog->window,
			prog->img_cat[3], prog->p_x * IMG_WIDTH, prog->p_y * IMG_HEIGHT);
	else if (prog->anim == 4 * ANIM)
		mlx_put_image_to_window(prog->mlx_p, prog->window,
			prog->img_cat[4], prog->p_x * IMG_WIDTH, prog->p_y * IMG_HEIGHT);
	else if (prog->anim == 5 * ANIM)
		mlx_put_image_to_window(prog->mlx_p, prog->window,
			prog->img_cat[5], prog->p_x * IMG_WIDTH, prog->p_y * IMG_HEIGHT);
	else if (prog->anim == 6 * ANIM)
		mlx_put_image_to_window(prog->mlx_p, prog->window,
			prog->img_cat[6], prog->p_x * IMG_WIDTH, prog->p_y * IMG_HEIGHT);
}

int	ft_sprite(t_program *prog)
{
	prog->anim++;
	prog->anim_e++;
	if (prog->end == 0)
	{
		ft_anim_cat(prog);
		ft_anim_cat_r(prog);
		ft_anim_enemy(prog);
		ft_anim_enemy_r(prog);
	}
	return (0);
}
