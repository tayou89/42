/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:35:40 by tayou             #+#    #+#             */
/*   Updated: 2023/05/10 20:52:42 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define KEY_PRESS			2
# define KEY_RELEASE		3
# define EVENT_ON_DESTROY	17
# define KEY_ESC			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2

# define LEFT				0
# define RIGHT				1
# define DOWN				2
# define UP					3

# define TRUE				1
# define FALSE				0

typedef struct s_node
{
	char			component;
	char			accessibility;
	int				check_count;
	struct s_node	*left;
	struct s_node	*right;
	struct s_node	*up;
	struct s_node	*down;
	struct s_node	*next;
}	t_node;

typedef struct s_map
{
	char	*file_path;
	char	*extension;
	char	**array;
	t_node	*linked_list;
	int		fd;
	int		line_count;
}	t_map;

typedef struct s_count
{
	int	exit;
	int	collectible;
	int	player;
	int	enemy;
	int	move;
	int	collect;
}	t_count;

typedef struct s_window
{
	int		block_size;
	int		x_size;
	int		y_size;
	void	*ptr;
}	t_window;

typedef struct s_minilibx
{
	void	*ptr;
}	t_minilibx;

typedef struct s_image
{
	void	*empty;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*done;
	void	*square_button;
	void	*player[4][4];
	void	*enemy[4][4];
	int		player_number;
	int		enemy_number;
}	t_image;

typedef struct s_player
{
	int	map_x;
	int	map_y;
	int	window_x;
	int	window_y;
	int	target_x;
	int	target_y;
	int	direction;
}	t_player;

typedef struct s_enemy
{
	int	*map_x;
	int	*map_y;
	int	window_x;
	int	window_y;
	int	target_x;
	int	target_y;
	int	direction;
	int	witness;
}	t_enemy;

typedef struct s_flag
{
	int		player_move;
	int		player_move_complete;
	int		enemy_move;
	int		find_invader;
	char	exit_open;
}	t_flag;

typedef struct s_component
{
	char	wall;
	char	empty_space;
	char	collectible;
	char	exit;
	char	player;
	char	enemy;
	char	target;
	int		map_x;
	int		map_y;
}	t_component;

typedef struct s_data
{
	t_map		map;
	t_count		count;
	t_window	window;
	t_minilibx	mlx;
	t_image		image;
	t_player	player;
	t_enemy		enemy;
	t_flag		flag;
	t_component	component;
	int			error_number;
}	t_data;

void	check_map_validation(int argc, char **argv, t_data *game);
void	check_map_extension(t_data *game);
int		check_map_is_rectangular(t_data *game);
int		check_map_surrounded_by_wall(t_data *game);
int		check_map_component(t_data *game);
int		check_map_has_valid_path(t_data *game);
t_node	*check_accessibility(t_node *map);

void	get_array_map(t_data *game);
t_node	*get_linked_list_map(char **array_map);

void	make_initial_game_setting(t_data *game);
void	get_image_address(t_data *game);
void	get_player_location(t_data *game);
void	get_enemy_location(t_data *game);

void	make_game(t_data *game);
void	when_key_is_pressed(t_data *game);
void	when_click_x_button_on_window(t_data *game);
void	when_key_not_pressed(t_data *game);
void	make_enemy_on_guard(t_data *game);
void	turn_enemy_to_direction(t_data *game);
void	check_every_enemy_if_find_invader(int *k, t_data *game);
void	move_enemy_to_direction(int *k, t_data *game);
void	make_player_move_to_target(t_data *game);

t_node	*get_new_node(char c);
t_node	*add_node_right(t_node *line, t_node *new_node);
t_node	*link_node_to_next(t_node *list, t_node *node_to_link);
t_node	*find_component_node(t_node *map, char component);
t_node	*find_left_node(t_node *node);

int		pass_white_space(char *string);
void	switch_newline_to_null(char *string);
char	get_last_character(char *string);
char	*get_last_line(char **string);
void	get_component_location(char component, t_data *game);
void	count_xy_by_direction(int *x, int *y, int dir);
void	count_dir_image_number(int *number);
void	get_enemy_target_location(t_data *game);
void	put_move_count_string(t_data *game);

void	free_mallocated_data(t_data *game);
void	free_2d_string_array(char **string);
void	free_linked_list(t_node *list);

int		finish_game_after_free(t_data *game);

#endif
