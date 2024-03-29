/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:35:40 by tayou             #+#    #+#             */
/*   Updated: 2023/04/28 13:22:44 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
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

typedef struct s_image
{
	void	*image;
}	t_image;

typedef struct s_data
{
	char	*map_file_path;
	char	**array_map;
	t_node	*linked_list_map;
	int		fd;
	int		map_line_count;
	int		exit_count;
	int		collectible_count;
	int		player_count;
	int		enemy_count;
	int		block_size;
	int		win_x_size;
	int		win_y_size;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*empty;
	void	*wall;
	void	*coll;
	void	*exit;
	void	*done;
	t_image	player[4][4];
	t_image	enemy[4][4];
	int		player_x;
	int		player_y;
	int		*enemy_x;
	int		*enemy_y;
	int		witness;
	int		enemy_target_x;
	int		enemy_target_y;
	int		current_x;
	int		current_y;
	int		target_x;
	int		target_y;
	int		current_direction;
	int		enemy_direction;
	int		component_x;
	int		component_y;
	int		move_count;
	int		collect_count;
}	t_data;

void	check_map_validation(int argc, char **argv, t_data *game);
void	check_map_extension(t_data *game);

int		check_map_is_rectangular(char **map);
int		check_map_surrounded_by_wall(char **map);
int		check_map_component(char **map, t_data *game);
int		check_map_has_valid_path(char **map, t_data *game);
t_node	*check_accessibility(t_node *map);

char	**get_array_map(char *map_file_path, t_data *game);
t_node	*get_linked_list_map(char **array_map);

void	make_game(t_data *game);

void	make_initial_game_setting(t_data *game);
void	get_mlx_win_ptr(t_data *game);
void	make_map(t_data *game);
void	get_player_location(t_data *game);
void	get_enemy_location(t_data *game);
void	control_player(t_data *game);
int		make_enemy_on_guard(t_data *game);

void	get_component_image_address(t_data *game);
void	put_image_to_map(t_data *game);

void	move_left(t_data *game);
void	move_right(t_data *game);
void	move_down(t_data *game);
void	move_up(t_data *game);
int		move_by_component(t_data *game);

void	set_sprite_image_to_left(t_data *game);
void	set_sprite_image_to_right(t_data *game);
void	set_sprite_image_to_up(t_data *game);
void	set_sprite_image_to_down(t_data *game);

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

void	free_mallocated_data(t_data *game);
void	free_2d_string_array(char **string);
void	free_linked_list(t_node *list);

int		finish_game_after_free(t_data *game);

void	print_linked_list_map(t_node *map);

#endif
