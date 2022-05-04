/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

# define EVENT_W 13
# define EVENT_A 0
# define EVENT_S 1
# define EVENT_D 2
# define EVENT_ESC 53
# define IMG_WIDTH 50
# define IMG_HEIGHT 50
# define PATH_IMG_1 "./img/img2/cat.xpm"
# define PATH_IMG_2 "./img/img2/fondo.xpm"
# define PATH_IMG_3 "./img/img2/wall2.xpm"
# define PATH_IMG_4 "./img/img2/food.xpm"
# define PATH_IMG_5 "./img/img2/woman.xpm"
# define PATH_IMG_6 "./img/img2/final.xpm"
# define PATH_IMG_7 "./img/img2/msg.xpm"

typedef struct s_program
{
	void	*mlx_p;
	void	*window;
	int		w_height;
	int		w_width;
	char	*name;
	char	**map;
	int		x;
	int		y;
	void	*img_1;
	void	*img_2;
	void	*img_3;
	void	*img_4;
	void	*img_5;
	void	*img_6;
	void	*img_7;
	int		food;
	int		width;
	int		height;
	int		p_x;
	int		p_y;
	int		move;
	int		end;
}	t_program;

typedef struct s_dim
{
	int	dim_x;
	int	dim_y;
}	t_dim;

int		check_map(char *args, t_dim *dim);
int		check_map_dim(ssize_t fd);
int		check_map_ext(char *args);
int		check_map_char(char *args);
int		check_map_walls(char *args, t_dim *dim);
t_dim	*get_dim(char *args, t_dim *dim);
int		validate_dim(ssize_t fd, int length, char *line);
int		validate_char(char *line);
int		validate_wall(char *line, int i, t_dim *dim);
int		ft_strlen_mod(char *line);
void	ft_print_error(int i);
void	ft_initialize_prog(t_program *prog, t_dim *dim);
void	ft_create_map(t_program *prog, char *args, t_dim *dim);
void	ft_get_map(int fd, t_program *prog, t_dim *dim);
void	ft_assign_values(t_program *prog, int i, char *line);
void	ft_initialize_img(t_program *prog);
void	ft_draw_map(t_program *prog, t_dim *dim);
void	ft_put_img(int l, int k, t_program *prog);
void	ft_start_game(t_program *prog, t_dim *dim);
int		ft_end_game(t_program *prog);
int		ft_key_event(int keycode, t_program **prog);
void	ft_move_1(t_program **prog, int x, int y);
void	ft_move_2(t_program **prog, int x, int y);
void	ft_move_3(t_program **prog, int x, int y);
void	ft_eval_move(t_program **prog, int x, int y);

#endif
