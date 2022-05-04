/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_b.h"

void	ft_move_5(t_program **prog, int x, int y)
{
	(*prog)->move++;
	mlx_put_image_to_window((*prog)->mlx_p, (*prog)->window,
		(*prog)->img_11, 90, (*prog)->score - 15);
	mlx_string_put((*prog)->mlx_p, (*prog)->window, 100, (*prog)->score,
		0x00FF0000, ft_itoa((*prog)->move));
	mlx_put_image_to_window((*prog)->mlx_p, (*prog)->window,
		(*prog)->img_2, (*prog)->p_x * IMG_WIDTH, (*prog)->p_y * IMG_HEIGHT);
	mlx_put_image_to_window((*prog)->mlx_p, (*prog)->window,
		(*prog)->img_cat[0], ((*prog)->p_x + x) * IMG_WIDTH,
		((*prog)->p_y + y) * IMG_HEIGHT);
	(*prog)->map[(*prog)->p_y + y][(*prog)->p_x + x] = 'P';
	(*prog)->map[(*prog)->p_y][(*prog)->p_x] = '0';
	(*prog)->p_x = (*prog)->p_x + x;
	(*prog)->p_y = (*prog)->p_y + y;
}

void	ft_move_4(t_program **prog, int x, int y)
{
	mlx_put_image_to_window((*prog)->mlx_p, (*prog)->window,
		(*prog)->img_9, (*prog)->p_x * IMG_WIDTH, (*prog)->p_y * IMG_HEIGHT);
	mlx_put_image_to_window((*prog)->mlx_p, (*prog)->window, (*prog)->img_2,
		((*prog)->p_x + x) * IMG_WIDTH, ((*prog)->p_y + y) * IMG_HEIGHT);
	mlx_put_image_to_window((*prog)->mlx_p, (*prog)->window, (*prog)->img_10,
		(((*prog)->w_width * IMG_WIDTH / 2)) - 100, 5);
	(*prog)->end = 1;
}

void	ft_move_3(t_program **prog, int x, int y)
{
	(*prog)->move++;
	mlx_put_image_to_window((*prog)->mlx_p, (*prog)->window,
		(*prog)->img_11, 90, (*prog)->score - 15);
	mlx_string_put((*prog)->mlx_p, (*prog)->window, 100, (*prog)->score,
		0x00FF0000, ft_itoa((*prog)->move));
	mlx_put_image_to_window((*prog)->mlx_p, (*prog)->window,
		(*prog)->img_2, (*prog)->p_x * IMG_WIDTH, (*prog)->p_y * IMG_HEIGHT);
	mlx_put_image_to_window((*prog)->mlx_p, (*prog)->window, (*prog)->img_6,
		((*prog)->p_x + x) * IMG_WIDTH, ((*prog)->p_y + y) * IMG_HEIGHT);
	mlx_put_image_to_window((*prog)->mlx_p, (*prog)->window, (*prog)->img_7,
		(((*prog)->w_width * IMG_WIDTH / 2)) - 100, 5);
	(*prog)->end = 1;
}

void	ft_move_2(t_program **prog, int x, int y)
{
	(*prog)->move++;
	mlx_put_image_to_window((*prog)->mlx_p, (*prog)->window,
		(*prog)->img_11, 90, (*prog)->score - 15);
	mlx_string_put((*prog)->mlx_p, (*prog)->window, 100, (*prog)->score,
		0x00FF0000, ft_itoa((*prog)->move));
	mlx_put_image_to_window((*prog)->mlx_p, (*prog)->window,
		(*prog)->img_2, (*prog)->p_x * IMG_WIDTH, (*prog)->p_y * IMG_HEIGHT);
	mlx_put_image_to_window((*prog)->mlx_p, (*prog)->window,
		(*prog)->img_cat[0], ((*prog)->p_x + x) * IMG_WIDTH,
		((*prog)->p_y + y) * IMG_HEIGHT);
	(*prog)->map[(*prog)->p_y + y][(*prog)->p_x + x] = 'P';
	(*prog)->map[(*prog)->p_y][(*prog)->p_x] = '0';
	(*prog)->p_x = (*prog)->p_x + x;
	(*prog)->p_y = (*prog)->p_y + y;
	(*prog)->food--;
	if ((*prog)->food == 0)
	{
		mlx_put_image_to_window((*prog)->mlx_p, (*prog)->window,
			(*prog)->img_5, (*prog)->p_x_e * IMG_WIDTH,
			(*prog)->p_y_e * IMG_HEIGHT);
		(*prog)->map[(*prog)->p_y_e][(*prog)->p_x_e] = 'E';
	}
}

void	ft_move_1(t_program **prog, int x, int y)
{
	(*prog)->move++;
	mlx_put_image_to_window((*prog)->mlx_p, (*prog)->window,
		(*prog)->img_11, 90, (*prog)->score - 15);
	mlx_string_put((*prog)->mlx_p, (*prog)->window, 100, (*prog)->score,
		0x00FF0000, ft_itoa((*prog)->move));
	mlx_put_image_to_window((*prog)->mlx_p, (*prog)->window,
		(*prog)->img_2, (*prog)->p_x * IMG_WIDTH, (*prog)->p_y * IMG_HEIGHT);
	mlx_put_image_to_window((*prog)->mlx_p, (*prog)->window,
		(*prog)->img_cat[0], ((*prog)->p_x + x) * IMG_WIDTH,
		((*prog)->p_y + y) * IMG_HEIGHT);
	(*prog)->map[(*prog)->p_y + y][(*prog)->p_x + x] = 'P';
	(*prog)->map[(*prog)->p_y][(*prog)->p_x] = '0';
	(*prog)->p_x = (*prog)->p_x + x;
	(*prog)->p_y = (*prog)->p_y + y;
}
