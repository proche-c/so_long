/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_b.h"

void	ft_print_error(int i)
{
	if (i == 1)
		write(1, "Fail to allocate memory\n", 24);
	else if (i == 2)
		write(1, "Type 2 valid arguments\n", 23);
	else if (i == 3)
		write(1, "Fail to open the map\n", 21);
	else if (i == 4)
		write(1, "Invalid map\n", 11);
}

int	ft_check_errors(t_program *prog, t_dim *dim, char *arg, int ac)
{
	if (!prog || !dim)
	{
		ft_print_error(1);
		return (-1);
	}
	else if (ac != 2)
	{
		ft_print_error(2);
		return (-1);
	}
	else if (check_map(arg, dim) == -1)
	{
		ft_print_error(4);
		return (-1);
	}
	else
		return (0);
}

int	main(int ac, char **args)
{
	t_program	*prog;
	t_dim		*dim;

	prog = (t_program *)malloc(sizeof(t_program));
	dim = (t_dim *)malloc(sizeof(int) * 2);
	if (ft_check_errors(prog, dim, args[1], ac) == -1)
	{
		free(prog);
		free(dim);
		exit(1);
	}
	else
	{
		ft_initialize_prog(prog, dim);
		ft_create_map(prog, args[1], dim);
		ft_start_game(prog, dim);
		mlx_key_hook(prog->window, ft_key_event, &prog);
		mlx_hook(prog->window, 17, 0, ft_end_game, prog);
		mlx_loop_hook(prog->mlx_p, ft_sprite, prog);
		mlx_loop(prog->mlx_p);
	}
	return (0);
}
