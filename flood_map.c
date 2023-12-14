/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:37:49 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/14 20:03:55 by brandebr         ###   ########.fr       */
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

int		flood_map(t_map *map, size_t x, size_t y)
{
		write(1, "1\n", 2);
		printf("hi\n");
		int		flag;
		flag = 0;
		if (map->map_cpy[x][y] == 'V' || map->map_cpy[x][y] == '1' 
						|| map->map_cpy[x][y] == 'E')
		{
				printf("0\n");
				if (map->map_cpy[x][y] == 'E')
						flag = 1;
				return (-1);
		}
		printf("Pasamos el 1 if\n");
		if (map->map_cpy[x][y] == 'C')
		{
				printf("1\n");
				map->coins_cpy--;
				map->map_cpy[x][y] = 'V';
		}
		if (flag)
		{
				printf("2\n");
				map->exit--;
				map->map_cpy[x][y] = 'V';
		}
				printf("3\n");
		map->map_cpy[x][y] = 'V';
		flood_map(map, x + 1, y);
		flood_map(map, x - 1, y);
		flood_map(map, x, y + 1);
		flood_map(map, x, y - 1);

		size_t		cont1;
		size_t		cont2;

		cont1 = 0;
		cont2 = 0;
		while (y < map->height && x < map->width)
		{

				printf("%c", map->map[y][x]);
				y++;
				if (y == map->height)
				{
						x++;
						y = 0;
				}
		}

		
		return (-1);
}
