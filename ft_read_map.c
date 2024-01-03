/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:01:03 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/03 19:45:29 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	write_error(void)
{
	write(1, "ERROR\n", 1);
	exit(-1);
}

void	ft_read_map(char **argv, t_map *game)
{
	int		fd;
	int fd1;
	int fd2;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		write_error();

game->map = ft_file_to_dptr_m(fd);

fd1 = open(argv[1], O_RDONLY);
fd2 = open(argv[1], O_RDONLY);
game->map_cpy = ft_file_to_dptr_m(fd1);
game->map_cpy2 = ft_file_to_dptr_m(fd2);

tokemo(game->map,0);
tokemo(game->map_cpy,0);
tokemo(game->map_cpy2,0);
}
/*int	ft_read_map(char **argv, t_map *game)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		write_error();
	line = get_next_line(fd);
	if (!line)
		write_error();
	game->raw_map = ft_strdup(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		game->raw_map = ft_strjoin(game->raw_map, line);
	}
	free(line);
	return (fd);
}*/

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
}

void	ft_measures(t_map *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	//game->map = ft_split(game->raw_map, '\n');
	if (!game->map[0])
	{
		write(2, "ERROR\nEmpty file", 16);
		free(game->map);
		exit (0);
	}
	while (game->map[0][x])
		x++;
	game->width = x;
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
		if (game->map[0][i] != '1' || game->map[game->height -1][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1')
			return (-1);
		if (game->map[i][game->width - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}
