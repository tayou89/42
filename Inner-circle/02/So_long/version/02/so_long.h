/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:35:40 by tayou             #+#    #+#             */
/*   Updated: 2023/04/15 22:58:19 by tayou            ###   ########.fr       */
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
	int				visit_count;
	struct s_node	*left;
	struct s_node	*right;
	struct s_node	*up;
	struct s_node	*down;
}	t_node;

void	check_map_extension(char *map_name);
void	check_map_validation(int argc, char **argv);

int		check_map_is_rectangular(char **map);
int		check_map_surrounded_by_wall(char **map);
int		check_map_component(char **map);
int		check_map_has_valid_path(char **map);

char	**get_2d_array_map(char *map_file_name);
char	**get_access_check_map(char **map);

t_node	*get_new_node(char c);
t_node	*add_node_right(t_node *line, t_node *new_node);

int		pass_white_space(char *string);
void	switch_newline_to_null(char *string);
char	get_last_character(char *string);
char	*get_last_line(char **string);

void	free_2d_string_array(char **string);

#endif
