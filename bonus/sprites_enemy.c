/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_b.h"

void	ft_move_enemy_r(t_program *prog, int i)
{
	if (prog->map[prog->p_y_enemy[i] + 1][prog->p_x_enemy[i]] == '0')
		ft_move_enemy_1(prog, i, 1, 0);
	else if (prog->map[prog->p_y_enemy[i] + 1][prog->p_x_enemy[i]] == 'P')
		ft_move_enemy_2(prog, i, 1, 0);
	else if (prog->map[prog->p_y_enemy[i]][prog->p_x_enemy[i] + 1] == '0')
		ft_move_enemy_1(prog, i, 0, 1);
	else if (prog->map[prog->p_y_enemy[i]][prog->p_x_enemy[i] + 1] == 'P')
		ft_move_enemy_2(prog, i, 0, 1);
	else if (prog->map[prog->p_y_enemy[i] - 1][prog->p_x_enemy[i]] == '0')
		ft_move_enemy_1(prog, i, -1, 0);
	else if (prog->map[prog->p_y_enemy[i] - 1][prog->p_x_enemy[i]] == 'P')
		ft_move_enemy_2(prog, i, -1, 0);
	else if (prog->map[prog->p_y_enemy[i]][prog->p_x_enemy[i] - 1] == '0')
		ft_move_enemy_1(prog, i, 0, -1);
	else if (prog->map[prog->p_y_enemy[i]][prog->p_x_enemy[i] - 1] == 'P')
		ft_move_enemy_2(prog, i, 0, -1);
}

void	ft_move_enemy(t_program *prog, int i)
{
	if (prog->map[prog->p_y_enemy[i]][prog->p_x_enemy[i] - 1] == '0')
		ft_move_enemy_1(prog, i, 0, -1);
	else if (prog->map[prog->p_y_enemy[i]][prog->p_x_enemy[i] - 1] == 'P')
		ft_move_enemy_2(prog, i, 0, -1);
	else if (prog->map[prog->p_y_enemy[i] - 1][prog->p_x_enemy[i]] == '0')
		ft_move_enemy_1(prog, i, -1, 0);
	else if (prog->map[prog->p_y_enemy[i] - 1][prog->p_x_enemy[i]] == 'P')
		ft_move_enemy_2(prog, i, -1, 0);
	else if (prog->map[prog->p_y_enemy[i]][prog->p_x_enemy[i] + 1] == '0')
		ft_move_enemy_1(prog, i, 0, 1);
	else if (prog->map[prog->p_y_enemy[i]][prog->p_x_enemy[i] + 1] == 'P')
		ft_move_enemy_2(prog, i, 0, 1);
	else if (prog->map[prog->p_y_enemy[i] + 1][prog->p_x_enemy[i]] == '0')
		ft_move_enemy_1(prog, i, 1, 0);
	else if (prog->map[prog->p_y_enemy[i] + 1][prog->p_x_enemy[i]] == 'P')
		ft_move_enemy_2(prog, i, 1, 0);
}

void	ft_anim_enemy_r(t_program *prog)
{
	int	i;

	if (prog->anim_e == 3 * ANIM_E)
	{
		i = -1;
		while (++i < prog->enemies)
			ft_move_enemy_r(prog, i);
	}
	if (prog->anim_e == 4 * ANIM_E)
	{
		i = -1;
		while (++i < prog->enemies)
			ft_move_enemy_r(prog, i);
		prog->anim_e = 0;
	}
}

void	ft_anim_enemy(t_program *prog)
{
	int	i;

	if (prog->anim_e == ANIM_E)
	{
		i = -1;
		while (++i < prog->enemies)
			ft_move_enemy(prog, i);
	}
	if (prog->anim_e == 2 * ANIM_E)
	{
		i = -1;
		while (++i < prog->enemies)
			ft_move_enemy(prog, i);
	}
}
