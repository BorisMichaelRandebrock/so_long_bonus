/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:28:26 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/22 17:42:39 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	ft_close(t_map *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
}

/*void	ft_free_map(t_map *game)
{
	int	c;

	c = 0;
	while (game->map[c])
	{
		free(game->map[c]);
		c++;
	}
	free(game->map);
}*/

int	ft_free_all(t_map *game)
{
	if (game->raw_map)
		free(game->raw_map);
	if (game->map)
		ft_free_map(game);
	ft_close(game);
	return (1);
}
