/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:35:40 by tayou             #+#    #+#             */
/*   Updated: 2023/04/16 23:29:01 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"

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

void	check_map_extension(char *map_name);
void	check_map_validation(int argc, char **argv);

int		check_map_is_rectangular(char **map);
int		check_map_surrounded_by_wall(char **map);
int		check_map_component(char **map);
int		check_map_has_valid_path(char **map);
t_node	*check_accessibility(t_node *map);


char	**get_2d_array_map(char *map_file_name);
t_node	*get_linked_list_map(char **array_map);

t_node	*get_new_node(char c);
t_node	*add_node_right(t_node *line, t_node *new_node);
t_node	*link_node_to_next(t_node *list, t_node *node_to_link);
t_node	*find_component_node(t_node *map, char component);
t_node	*find_left_node(t_node *node);

int		pass_white_space(char *string);
void	switch_newline_to_null(char *string);
char	get_last_character(char *string);
char	*get_last_line(char **string);

void	free_2d_string_array(char **string);
void	free_linked_list(t_node *list);

void	print_linked_list_map(t_node *map);

#endif
