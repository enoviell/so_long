/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:11:11 by gpecci            #+#    #+#             */
/*   Updated: 2023/02/27 17:12:33 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_wall(t_game *game)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1' && (y == 0 || y == (i - 1)
				|| x == 0 || x == (int)(ft_strlen(game->map[0]) - 1)))
				draw_img(game, game->img_wall2, x, y);
			else if (game->map[y][x] == '1' && (y != 0 || y != (i - 1)
				|| x != 0 || x != (int)(ft_strlen(game->map[0]) - 1)))
				draw_img(game, game->img_wall, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
