/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:37:49 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/03 18:26:41 by brandebr         ###   ########.fr       */
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
		if ((unsigned int)c == game->width + 1)
			return (0);
		map_cpy[c] = ft_strdup(game->map[c]);
		c++;
	}
	map_cpy[c] = NULL;
	game->exit = 1;
	game->ex = 0;
	return (map_cpy);
}

int	flood_map(t_map *game, size_t x, size_t y)
{
//	printf("%c\n", game->map_cpy[x][y]);
	if (game->map_cpy[x][y] == 'V' || game->map_cpy[x][y] == '1'
					|| (game->map_cpy[x][y] == 'E' && game->coins_cpy != 0))
		return (-1);
//	printf("%c\n", game->map_cpy[x][y]);
	if (game->map_cpy[x][y] == 'C')
	{
		game->coins_cpy--;
		game->map_cpy[x][y] = 'V';
		if (game->coins_cpy == 0)
			game->flag = 1;
	}
/*	if (game->map_cpy[x][y] == 'E' && game->coins_cpy == 0)
	{
		game->map_cpy[x][y] = 'V';
	}*/
	game->map_cpy[x][y] = 'V';
	flood_map(game, x + 1, y);
	flood_map(game, x - 1, y);
	flood_map(game, x, y + 1);
	flood_map(game, x, y - 1);
	return (-1);
}
/*
void	ft_check_exit(t_map *game, size_t x, size_t y)
{
//	if ((y < 0 || x < 0) || (y == game->height) || (x == game->width))
//		return ;
	if ((game->map_cpy2[x][y] == 'V') || (game->map_cpy2[x][y] == '1'))
		return ;
	if (game->map_cpy2[x][y] == 'E')
	{
		game->ex++;
	}
	game->map_cpy2[x][y] = 'V';
	ft_check_exit(game, x -1, y);
	ft_check_exit(game, x, y +1);
	ft_check_exit(game, x +1, y);
	ft_check_exit(game, x, y -1);
	return ;
}*/
/*int	flood_map(t_map *game, size_t x, size_t y)
{
	int		flag;

	game->exit = 1;
	flag = 0;
	if (game->map_cpy[x][y] == 'V' || game->map_cpy[x][y] == '1'
					|| game->map_cpy[x][y] == 'E')
	{
		if (game->map_cpy[x][y] == 'E' && flag == 1)
		{
			game->exit--;
			if (game->exit == 0)
				return (0);
		}
		return (-1);
	}
	if (game->map_cpy[x][y] == 'C')
	{
		game->coins_cpy--;
		game->map_cpy[x][y] = 'V';
		if (game->coins_cpy == 0)
			flag = 1;
	}
	if (game->map_cpy[x][y] == 'E' && flag == 1)
	{
		game->exit--;
		game->map_cpy[x][y] = 'V';
	}
	game->map_cpy[x][y] = 'V';
	flood_map(game, x + 1, y);
	flood_map(game, x - 1, y);
	flood_map(game, x, y + 1);
	flood_map(game, x, y - 1);
	return (-1);
}*/
