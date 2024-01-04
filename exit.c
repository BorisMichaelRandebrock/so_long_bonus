/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:28:26 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/04 13:09:54 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_map *game)
{
	ft_free_map(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
	return (0);
}
