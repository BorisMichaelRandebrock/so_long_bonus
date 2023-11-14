/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:18:47 by brandebr          #+#    #+#             */
/*   Updated: 2023/11/14 17:02:39 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_name(char	*fn)
{
		char	*end;
		int		i;
		int		j;

		i = 0;
		j = 0;
		end	= ".ber";
		while (fn[i])
				i++;
		i = i - 4;
		while (fn[i])
		{
				if (fn[i++] == end[j++])
						continue ;
				else
						return (-1);
		}
		return (0);
}

int parse_it(int argc, char **argv)
{
		if (argc != 2)
		{
				write(2, "Error\nIncorrect number of arguments", 34);
				exit (0);
		}
		if (open(argv[1], O_RDONLY) != 0)
		{
				write(2, "Error\nEmpty file", 15);
				exit (0);
		}
		if (open(argv[1], O_RDONLY) == -1)
		{
				write(2, "Error\nWrong file reading", 23);
				exit (0);
		}
		if (file_name(argv[1]) == -1)
		{
				write(2, "Error\nWrong file type", 20);
				exit (0);
		}
		return (0);
}

