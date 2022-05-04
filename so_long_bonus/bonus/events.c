/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_b.h"

void	ft_eval_move(t_program **prog, int x, int y)
{
	if ((*prog)->map[(*prog)->p_y + y][(*prog)->p_x + x] == '0')
		ft_move_1(&(*prog), x, y);
	else if ((*prog)->map[(*prog)->p_y + y][(*prog)->p_x + x] == 'E'
		&& (*prog)->food != 0)
		ft_move_5(&(*prog), x, y);
	else if ((*prog)->map[(*prog)->p_y + y][(*prog)->p_x + x] == 'C')
		ft_move_2(&(*prog), x, y);
	else if ((*prog)->map[(*prog)->p_y + y][(*prog)->p_x + x] == 'E' &&
		(*prog)->food == 0)
		ft_move_3(&(*prog), x, y);
	else if ((*prog)->map[(*prog)->p_y + y][(*prog)->p_x + x] == 'N')
		ft_move_4(&(*prog), x, y);
}

int	ft_key_event(int keycode, t_program **prog)
{
	if (keycode == EVENT_D & (*prog)->end == 0)
		ft_eval_move(&(*prog), 1, 0);
	else if (keycode == EVENT_A & (*prog)->end == 0)
		ft_eval_move(&(*prog), -1, 0);
	else if (keycode == EVENT_W & (*prog)->end == 0)
		ft_eval_move(&(*prog), 0, -1);
	else if (keycode == EVENT_S & (*prog)->end == 0)
		ft_eval_move(&(*prog), 0, 1);
	if (keycode == EVENT_ESC)
	{
		ft_end_game(*prog);
		return (0);
	}
	return (0);
}
