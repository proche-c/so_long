/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map_walls(char *args, t_dim *dim)
{
	char	*line;
	int		i;
	ssize_t	fd;

	dim = get_dim(args, dim);
	fd = open(args, O_RDONLY);
	i = 1;
	while (i <= dim->dim_y)
	{
		line = get_next_line(fd);
		if (validate_wall(line, i, dim) == -1)
			return (-1);
		i++;
		free(line);
	}
	close(fd);
	return (0);
}

int	check_map_char(char *args)
{
	char	*line;
	ssize_t	fd;

	fd = open(args, O_RDONLY);
	line = get_next_line(fd);
	if (validate_char(line) == -1)
		return (-1);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			if (validate_char(line) == -1)
				return (-1);
		}
	}
	free(line);
	close(fd);
	return (0);
}

int	check_map_ext(char *args)
{
	int	i;

	i = ft_strlen_mod(args);
	if (args[i - 1] == 114 && args[i - 2] == 101 && args[i - 3] == 98
		&& args[i - 4] == 46)
		return (0);
	else
		return (-1);
}

int	check_map_dim(ssize_t fd)
{
	char	*line;
	int		length;
	int		result;

	line = get_next_line(fd);
	if (line)
	{
		length = ft_strlen_mod(line);
		if (validate_dim(fd, length, line) == -1)
			result = -1;
		else
			result = 0;
	}
	else
		result = -1;
	close(fd);
	return (result);
}

int	check_map(char *args, t_dim *dim)
{
	ssize_t	fd;

	fd = open(args, O_RDONLY);
	if (fd < 0)
	{
		ft_print_error(3);
		return (-1);
	}
	else if (check_map_dim(fd) == -1)
		return (-1);
	else if (check_map_ext(args) == -1)
		return (-1);
	else if (check_map_char(args) == -1)
		return (-1);
	else if (check_map_walls(args, dim) == -1)
		return (-1);
	else
		return (0);
}
