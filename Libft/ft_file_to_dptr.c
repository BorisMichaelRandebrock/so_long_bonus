/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_dptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:22:19 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/05 10:37:15 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char **ft_file_to_dptr_m(int fd)
{
    char	**lines;
	char	*line;
    size_t	line_count;
    char	**new_lines;

    lines = NULL;
    line_count = 0;
    while (42)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        new_lines = malloc((line_count + 2) * sizeof(char *));
        if (new_lines == NULL)
            return NULL;
        size_t i = 0;
        while (i < line_count)
        {
            new_lines[i] = lines[i];
            i++;
        }
        new_lines[line_count] = line;
        new_lines[line_count + 1] = NULL;
        free(lines);
        lines = new_lines;
        line_count++;
    }
    return lines;
}
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
}*/
