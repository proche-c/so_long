/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen_mod(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	return (i);
}

int	validate_wall(char *line, int i, t_dim *dim)
{
	int	j;

	if (i == 1 || i == dim->dim_y)
	{
		j = 0;
		while (j < dim->dim_x)
		{
			if (line[j++] != '1')
				return (-1);
		}
	}
	else
	{
		if (line[0] != '1' || line[dim->dim_x - 1] != '1')
			return (-1);
	}
	return (0);
}

int	validate_char(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'C'
			&& line[i] != 'P' && line[i] != 'E')
			return (-1);
		i++;
	}
	return (0);
}

int	validate_dim(ssize_t fd, int length, char *line)
{
	int	temp;

	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			temp = ft_strlen_mod(line);
			if (temp != length)
				return (-1);
		}
	}
	return (0);
}

t_dim	*get_dim(char *args, t_dim *dim)
{
	ssize_t	fd;
	char	*line;

	fd = open(args, O_RDONLY);
	line = get_next_line(fd);
	dim->dim_x = ft_strlen_mod(line);
	dim->dim_y = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			dim->dim_y++;
	}
	free(line);
	close(fd);
	return (dim);
}
