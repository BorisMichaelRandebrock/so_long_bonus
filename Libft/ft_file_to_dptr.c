/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_dptr_m.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:22:19 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/04 14:40:09 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include "so_long.h"

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

