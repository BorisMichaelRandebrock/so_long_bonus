/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:17:48 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/05 18:58:10 by brandebr         ###   ########.fr       */
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
		char	**path;
		size_t	height;
		size_t	width;
		size_t	coins;
		size_t	coins_cpy;
		size_t	exits;
		size_t player;
		t_pos	start;
		t_pos	exit;
}				t_map;

int		parse_it(int argc, char **argv);// parse_it.c
int 	file_name(char  *fn); // parse_it.c
char	*get_next_line(int fd);
void	write_error(void); //ft_read_map.c
int		ft_read_map(char **argv, t_map *game); //ft_read_map.c
void	ft_measures(t_map *game);//ft_read_map.c
int     ft_outer_limits(t_map *game); //parse_it.c
int		exit_player_check(t_map *game); //parse_it.c
int     ft_collectibles(t_map *game); //parse_it.c
int		ft_square_check(t_map *game); // paarse_it.c								  
void    ft_free_map(t_map *game); //read_map
#endif
