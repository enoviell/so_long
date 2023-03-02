/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:36:59 by enoviell          #+#    #+#             */
/*   Updated: 2023/03/01 19:40:11 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(char *s, char *t, t_game *game)
{
	game->img_enemy = mlx_xpm_file_to_image(game->mlx,
			s, &game->img_w, &game->img_h);
	game->img_colect = mlx_xpm_file_to_image(game->mlx,
			t, &game->img_w, &game->img_h);
}

int	animation(t_game *game)
{
	if (game->loop < 1000)
	{
		game->loop++;
		return (0);
	}
	game->loop = 0;
	mlx_destroy_image(game->mlx, game->img_enemy);
	mlx_destroy_image(game->mlx, game->img_colect);
	if (game->pos_enemy == 1)
		put_image("images/enemy1.xpm", "images/collect1.xpm", game);
	else if (game->pos_enemy == 2)
		put_image("images/enemy2.xpm", "images/collect2.xpm", game);
	else if (game->pos_enemy == 3)
		put_image("images/enemy3.xpm", "images/collect3.xpm", game);
	else if (game->pos_enemy == 4)
		put_image("images/enemy4.xpm", "images/collect4.xpm", game);
	else
	{
		put_image("images/enemy5.xpm", "images/collect5.xpm", game);
		game->pos_enemy = 0;
	}
	draw_map(game);
	game->pos_enemy++;
	return (0);
}
