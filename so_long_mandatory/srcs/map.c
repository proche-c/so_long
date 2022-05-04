/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_img(int l, int k, t_program *prog)
{
	if (prog->map[k][l] == 49)
		mlx_put_image_to_window(prog->mlx_p, prog->window,
			prog->img_3, l * IMG_WIDTH, k * IMG_HEIGHT);
	else if (prog->map[k][l] == '0')
		mlx_put_image_to_window(prog->mlx_p, prog->window,
			prog->img_2, l * IMG_WIDTH, k * IMG_HEIGHT);
	else if (prog->map[k][l] == 'P')
	{
		mlx_put_image_to_window(prog->mlx_p, prog->window,
			prog->img_1, l * IMG_WIDTH, k * IMG_HEIGHT);
		prog->p_y = k;
		prog->p_x = l;
	}
	else if (prog->map[k][l] == 'C')
		mlx_put_image_to_window(prog->mlx_p, prog->window,
			prog->img_4, l * IMG_WIDTH, k * IMG_HEIGHT);
	else if (prog->map[k][l] == 'E')
		mlx_put_image_to_window(prog->mlx_p, prog->window,
			prog->img_5, l * IMG_WIDTH, k * IMG_HEIGHT);
}

void	ft_draw_map(t_program *prog, t_dim *dim)
{
	int	k;
	int	l;

	k = 0;
	while (k < dim->dim_y)
	{
		l = 0;
		while (l < dim->dim_x)
		{
			ft_put_img(l, k, prog);
			l++;
		}
		k++;
	}
}

void	ft_assign_values(t_program *prog, int i, char *line)
{
	int	j;

	j = 0;
	while (line[j] != '\n' && line[j] != '\0' && prog->map[i])
	{
		prog->map[i][j] = line[j];
		j++;
	}
	prog->map[i][j] = '\0';
}

void	ft_get_map(int fd, t_program *prog, t_dim *dim)
{
	int		i;
	char	*line;

	i = -1;
	while (++i < prog->height)
	{
		line = get_next_line(fd);
		if (line)
		{
			prog->map[i] = (char *)malloc(sizeof(char) * (dim->dim_x + 1));
			if (!prog->map[i])
			{
				ft_print_error(1);
				free(prog->map);
				free(prog);
				free(line);
				exit(1);
			}
			else
				ft_assign_values(prog, i, line);
			free(line);
		}
	}
}

void	ft_create_map(t_program *prog, char *args, t_dim *dim)
{
	int	fd;

	prog->map = (char **)malloc(sizeof(char) * (dim->dim_x + 1)
			* (dim->dim_y));
	if (!prog->map)
	{
		ft_print_error(1);
		free(prog);
		exit(1);
	}
	fd = open(args, O_RDONLY);
	if (fd < 0)
	{
		ft_print_error(3);
		free(prog);
		exit(1);
	}
	ft_get_map(fd, prog, dim);
	close(fd);
	ft_initialize_img(prog);
	ft_draw_map(prog, dim);
}
