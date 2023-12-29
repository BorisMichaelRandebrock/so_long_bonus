/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:11:19 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/29 13:49:13 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_w(t_map *game)
{
		long int	count;

		count = 0;
		if ((game->map[game->player.x - 1][game->player.y] != '1')
						&& (game->player.x - 1 && game->player.y != 'E'))
		{
				if (game->player.x - 1 && game->player.y == 'C')
						game->coins = game->coins -1;
			//	(game->player.x = '0') && (game->player.y = '0');
				game->map[game->player.x][game->player.y] = '0';
				game->player.x = game->player.x - 1;
			//	(game->player.x = 'P') && (game->player.y = 'P');
				game->map[game->player.x][game->player.y] = 'P';
				game->count = game->count + 1;
				ft_printf("Movements number: %d\n", game->count);
				ft_print_map (game);
		}
		else if (game->coins == 0 && (game->player.x -1 == 'E') 
						&& (game->player.y == 'E'))
				ft_win(game);
		return (0);
}

int	ft_move_s(t_map *game)
{
		long int	count;

		count = 0;
		if ((game->map[game->player.x + 1][game->player.y] != '1')
						&& (game->player.x + 1 && game->player.y != 'E'))
		{
				if (game->player.x +1 && game->player.y == 'C')
						game->coins = game->coins -1;
			//	(game->player.x = '0') && (game->player.y = '0');
				game->map[game->player.x][game->player.y] = '0';
				game->player.x = game->player.x +1;
			//	(game->player.x = 'P') && (game->player.y = 'P');
				game->map[game->player.x][game->player.y] = 'P';
				game->count = game->count +1;
				ft_printf("Movements number: %d\n", game->count);
				ft_print_map (game);
		}
		else if ((game->coins == 0) && (game->player.x + 1 == 'E') 
						&& (game->player.y == 'E'))
				ft_win(game);
		return (0);
}

int	ft_move_a(t_map *game)
{
		long int	count;

		count = 0;
		if ((game->map[game->player.x][game->player.y -1]  != '1')
						&& (game->player.x && game->player.y - 1 != 'E'))
		{
				//printf("1\n %zu, %zu\n", game->player.x, game->player.y);
				if (game->player.x && game->player.y - 1 == 'C')
						game->coins = game->coins - 1;
				//(game->player.x = '0') && (game->player.y = '0');
				game->map[game->player.x][game->player.y] = '0';
				game->player.y = game->player.y -1 ;
				game->map[game->player.x][game->player.y] = 'P';
//				(game->player.x = 'P') && (game->player.y = 'P');
				game->count = game->count + 1;
				ft_printf("Movements number: %d\n", game->count);
				ft_print_map (game);
		}
		else if (game->coins == 0 && (game->player.x == 'E') 
						&& (game->player.y - 1 == 'E'))
				ft_win(game);
		return (0);
}

int	ft_move_d(t_map *game)
{
		long int	count;

		count = 0;
		if ((game->map[game->player.x][game->player.y +1] != '1')
						&& (game->player.x && game->player.y +1 != 'E'))
		{
				if (game->player.x && game->player.y +1 == 'C')
						game->coins = game->coins -1;
				game->map[game->player.x][game->player.y] = '0';
//				(game->player.x == '0') && (game->player.y = '0');
				game->player.y = game->player.y +1;
				game->map[game->player.x][game->player.y] = 'P';
//				(game->player.x = 'P') && (game->player.y = 'P');
				game->count = game->count +1;
				ft_printf("Movements number: %d\n", game->count);
				ft_print_map (game);
		}
		else if (game->coins == 0 && (game->player.x =='E') && (game->player.y +1 == 'E'))
				ft_win(game);
		return (0);
}
int	ft_move(int keycode, t_map *game)
{
		if (keycode == 13)
				ft_move_w(game);
		if (keycode == 0)
				ft_move_a(game);
		if (keycode == 1)
				ft_move_s(game);
		if (keycode == 2)
				ft_move_d(game);
		if (keycode == 53)
				exit(1);
		return (0);
}

void	ft_win(t_map *game)
{
		int	c;

		c = 0;
		game->count = game->count +1;
		ft_printf("Movements number: %d\n", game->count);
		mlx_string_put(game->mlx_ptr, game->win_ptr, 15,
						15, 66000000, "CONGRATULATIONS\n");
		mlx_do_sync(game->mlx_ptr);
		while (c < 1000000000)
				c++;
		ft_free_all(game);
		exit(-1);
}
