/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:17:48 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/14 19:44:39 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"

typedef struct s_pos
{
		size_t	x;
		size_t	y;
}				t_pos;

typedef struct s_map
{
		char	*raw_map;
		char	**map;
		char	**map_cpy;
		char	**path;
		size_t	height;
		size_t	width;
		size_t	coins;
		size_t	coins_cpy;
		size_t	exits;
		size_t player;
		int		count;
		t_pos	start;
		int		exit;
}				t_map;

int		parse_it(int argc, char **argv);// parse_it.c
int 	file_name(char  *fn); // parse_it.c
char	*get_next_line(int fd);
void	write_error(void); //ft_read_map.c
int		ft_read_map(char **argv, t_map *game); //ft_read_map.c
void	ft_measures(t_map *game);//ft_read_map.c
int     ft_outer_limits(t_map *game); //parse_it.c -> moved to read_map.c
int		exit_player_check(t_map *game); //parse_it.c
int     ft_collectibles(t_map *game); //parse_it.c
int		ft_rectangle_check(t_map *game); // paarse_it.c								
void    ft_free_map(t_map *game); //ft_read_map.c
char	**cpy_map(t_map *game); //flood_map.c
int		flood_map(t_map *map, size_t x, size_t y);//flood_map.c
int     map_check(t_map *game); //main.c
int		player_position(t_map *game);//main.c

#endif
