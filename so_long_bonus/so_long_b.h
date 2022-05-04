/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_b.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_B_H
# define SO_LONG_B_H

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
# define ANIM 800
# define ANIM_E 8000
# define PATH_IMG_CAT_0 "./img/img_b/cat/cat_0.xpm"
# define PATH_IMG_CAT_1 "./img/img_b/cat/cat_1.xpm"
# define PATH_IMG_CAT_2 "./img/img_b/cat/cat_2.xpm"
# define PATH_IMG_CAT_3 "./img/img_b/cat/cat_3.xpm"
# define PATH_IMG_CAT_4 "./img/img_b/cat/cat_4.xpm"
# define PATH_IMG_CAT_5 "./img/img_b/cat/cat_5.xpm"
# define PATH_IMG_CAT_6 "./img/img_b/cat/cat_6.xpm"
# define PATH_IMG_2 "./img/img_b/fondo.xpm"
# define PATH_IMG_3 "./img/img_b/wall2.xpm"
# define PATH_IMG_4 "./img/img_b/food.xpm"
# define PATH_IMG_5 "./img/img_b/woman.xpm"
# define PATH_IMG_6 "./img/img_b/final.xpm"
# define PATH_IMG_7 "./img/img_b/msg.xpm"
# define PATH_IMG_8 "./img/img_b/enemy.xpm"
# define PATH_IMG_9 "./img/img_b/lose.xpm"
# define PATH_IMG_10 "./img/img_b/msg_l.xpm"
# define PATH_IMG_11 "./img/img_b/black.xpm"

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
	void	*img_cat[7];
	void	*img_2;
	void	*img_3;
	void	*img_4;
	void	*img_5;
	void	*img_6;
	void	*img_7;
	void	*img_8;
	void	*img_9;
	void	*img_10;
	void	*img_11;
	int		food;
	int		enemies;
	int		*p_x_enemy;
	int		*p_y_enemy;
	int		width;
	int		height;
	int		p_x;
	int		p_y;
	int		p_x_e;
	int		p_y_e;
	int		move;
	int		end;
	int		anim;
	int		anim_e;
	int		score;
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
void	ft_initialize_cat(t_program *prog);
void	ft_draw_map(t_program *prog, t_dim *dim);
void	ft_put_img(int l, int k, t_program *prog);
void	ft_start_game(t_program *prog, t_dim *dim);
int		ft_count_food(t_program *prog, t_dim *dim);
void	ft_count_enemy(t_program *prog, t_dim *dim);
int		ft_end_game(t_program *prog);
int		ft_key_event(int keycode, t_program **prog);
void	ft_move_1(t_program **prog, int x, int y);
void	ft_move_2(t_program **prog, int x, int y);
void	ft_move_3(t_program **prog, int x, int y);
void	ft_move_4(t_program **prog, int x, int y);
void	ft_move_5(t_program **prog, int x, int y);
void	ft_eval_move(t_program **prog, int x, int y);
int		ft_sprite(t_program *prog);
void	ft_anim_cat(t_program *prog);
void	ft_anim_enemy(t_program *prog);
void	ft_anim_enemy_r(t_program *prog);
void	ft_move_enemy(t_program *prog, int i);
void	ft_move_enemy_r(t_program *prog, int i);
void	ft_move_enemy_1(t_program *prog, int i, int y, int x);
void	ft_move_enemy_2(t_program *prog, int i, int y, int x);

#endif
