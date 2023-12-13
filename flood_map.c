/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:37:49 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/13 18:28:41 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**cpy_map(t_map *game)
{
		int		c;
		char	**map_cpy;

		c = 0;
		map_cpy = (char **)malloc(sizeof(char *) * (game->width + 1));
		if (!map_cpy)
				return (NULL);
		while (game->map[c])
		{
				map_cpy[c] = ft_strdup(game->map[c]);
				c++;
		}
		map_cpy[c] = NULL;
		game->exit = 1;
		return (map_cpy);
}

int		flood_map(t_map *map, int x, int y)
{
		int		flag;
		flag = 0;
		if (map->map_cpy[x][y] == 'V' || map->map_cpy[x][y] == '1' 
						|| map->map_cpy[x][y] == 'E')
		{
				if (map->map_cpy[x][y] == 'E')
						flag = 1;
				return (-1);
		}
		if (map->map_cpy[x][y] == 'C')
		{
				map->coins_cpy--;
				map->map_cpy[x][y] = 'V';
		}
		if (flag)
		{
				map->exit--;
				map->map_cpy[x][y] = 'V';
		}
		map->map_cpy[x][y] = 'V';
		flood_map(map, x + 1, y);
		flood_map(map, x - 1, y);
		flood_map(map, x, y + 1);
		flood_map(map, x, y - 1);
		return (-1);
}
