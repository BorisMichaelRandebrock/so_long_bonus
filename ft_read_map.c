/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:01:03 by brandebr          #+#    #+#             */
/*   Updated: 2023/11/29 18:44:14 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_error(void)
{
		write(1, "ERROR\n", 1);
		exit(-1);
}

int	ft_read_map(char **argv, t_map map)
{
		int		fd;
		char	*line;

		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
				write_error();
		line = get_next_line(fd);
		if (!line)
				write_error();
		return (fd);
}

