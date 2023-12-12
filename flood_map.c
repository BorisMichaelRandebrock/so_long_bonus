/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:37:49 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/12 20:09:34 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**cpy_map(t_map *mapp)
{
		int		c;
		char	**map_cpy;
		t_pos	ex;

		c = 0;
		ex.x = 1;
		ex.y = 1;
		map_cpy = (char **)malloc(sizeof(char *) * (mapp->width + 1));
		if (!map_cpy)
				return (NULL);
		while (mapp->map[c])
		{
				map_cpy[c] = ft_strdup(mapp->map[c]);
				c++;
		}
		map_cpy[c] = NULL;
		mapp->exit = ex;
		return (map_cpy);
}

void	flood_map(t_map **map, t_pos start)
{

}
