/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:01:03 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/04 14:45:57 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
char	**ft_file_to_dptr_m(int fd)
{
	char	**lines;
	char	*line;
	size_t	line_count;

	lines = NULL;
	line_count = 0;
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		lines = realloc(lines, (line_count + 1) * sizeof(char *));
		lines[line_count] = line;
		line_count++;
	}
	lines = realloc(lines, (line_count + 1) * sizeof(char *));
	lines[line_count] = NULL;
	return (lines);
}
*/
void	ft_read_map(char **argv, t_map *game)
{
	int	fd;
	int	fd1;

	fd = open(argv[1], O_RDONLY);
	fd1 = open(argv[1], O_RDONLY);
	if (fd == -1 || fd1 == -1)
		exit_error(NULL, "ERROR\nFile could'nt be opened", 1);
	game->map = ft_file_to_dptr_m(fd);
	game->map_cpy = ft_file_to_dptr_m(fd1);

	printf("Maps read\n");
	tokemo(game->map,0);
	printf("\n");
	tokemo(game->map_cpy,0);
	printf("\n");
}

void	ft_free_map(t_map *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	i = 0;
	while (game->map_cpy[i])
	{
		free(game->map_cpy[i]);
		i++;
	}
	free(game->map_cpy);
}

void	ft_measures(t_map *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (game->map[0][x])
		x++;
	game->width = x - 1;
	while (game->map[y])
		y++;
	game->height = y;
}

int	ft_outer_limits(t_map *game)
{
	unsigned long		i;

	i = 0;
	while (i < game->width)
	{
//		ft_printf("game width %i\t%i\n", game->width, i);
		if (game->map[0][i] != '1' || game->map[game->height -1][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (i < game->height)
	{
//			ft_printf("game height%i\n", game->height);
		if (game->map[i][0] != '1')
			return (-1);
		if (game->map[i][game->width - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}
