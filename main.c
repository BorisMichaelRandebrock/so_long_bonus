/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:26:44 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/04 13:09:08 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(t_map *game, char *str, int mod)
{
	size_t	size;

	size = ft_strlen(str);
	if (!mod)
		ft_free_map(game);
	write(2, str, size);
	exit(1);
}

void	player_position(t_map *game)
{
	game->player.x = 0;
	game->player.y = 0;
	while (game->player.y <= game->height && game->player.x <= game->width)
	{
		if (game->map[game->player.y][game->player.x] == 'P')
			return ;
		game->player.x++;
		if (game->player.x == game->width)
		{
			game->player.x = 0;
			game->player.y++;
		}
	}
}

void	map_check(t_map *game)
{
	if (ft_outer_limits(game) == -1)
		exit_error(game, "ERROR\nThe Board is not correctly defined\n", 0);
	else if ((ft_collectibles(game) == -1) || (exit_player_check(game) == -1))
		exit_error(game, "ERROR\nWrong Players, exits or collectibles\n", 0);
	ft_rectangle_check(game);
	player_position(game);
	flood_map(game, game->player.x, game->player.y);

	printf("Maps flooded\n");
	tokemo(game->map,0);
	printf("\n");
	tokemo(game->map_cpy,0);
	printf("\n");

	ft_check_exit(game);
}

void	ft_win(t_map *game)
{
	int	c;

	c = 0;
	game->count = game->count +1;
	ft_printf("Total number of movements: %d\n", game->count);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 15,
		30, 0xFFFFFF, "CONGRATULATIONS YOU WIN!!!\n");
	mlx_do_sync(game->mlx_ptr);
	while (c < 1000000000)
		c++;
	ft_close(game);
}

#include <stdio.h>

void tokemo(char **arr, int line)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i] != NULL)
	{
		printf("%s", arr[i]);
		if (line)
			printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map	game;

	game.count = 0;
	parse_it(argc, argv);
	ft_read_map(argv, &game);
	ft_measures(&game);
	map_check(&game);
	game.mlx_ptr = mlx_init();
	ft_upload_img(&game);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.width * SIZE,
			game.height * SIZE, "a link to the past..");
	if (game.win_ptr == NULL)
		exit_error(NULL, "ERROR\nUnable to create a window\n", 1);
	ft_print_map(&game);
	mlx_hook(game.win_ptr, 2, 0, ft_move, &game);
	mlx_hook(game.win_ptr, 17, 0, ft_close, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
