/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:17:48 by brandebr          #+#    #+#             */
/*   Updated: 2023/11/09 17:45:05 by brandebr         ###   ########.fr       */
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
		char	**map;
		char	**path;
		size_t	height;
		size_t	width;
		size_t	coins;
		size_t	exits;
		size_t player;
		t_pos	start;
		t_pos	exit;
}				t_map;

int		parse_it(int argc, char **argv);

#endif
