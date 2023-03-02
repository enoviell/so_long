/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:29:33 by enoviell          #+#    #+#             */
/*   Updated: 2023/02/27 16:49:51 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_image(t_game *game)
{
	game->img_backg = mlx_xpm_file_to_image(game->mlx,
			"images/back.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"images/E2.xpm", &game->img_w, &game->img_h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"images/wall1.xpm", &game->img_w, &game->img_h);
	game->img_wall2 = mlx_xpm_file_to_image(game->mlx,
			"images/interno.xpm", &game->img_w, &game->img_h);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"images/ashdown.xpm", &game->img_w, &game->img_h);
	game->img_colect = mlx_xpm_file_to_image(game->mlx,
			"images/collect1.xpm", &game->img_w, &game->img_h);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx,
			"images/enemy1.xpm", &game->img_w, &game->img_h);
}

static void	init_window(t_game *game)
{
	int	i;

	game->map_w = ft_strlen(game->map[0]) * 64 ;
	i = 0;
	while (game->map[i])
		i++;
	game->map_h = i * 64 + 64 ;
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	init_window(game);
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "so_long");
	game->moves = 0;
	game->endgame = 0;
	game->pos_enemy = 1;
	game->loop = 0;
	init_image(game);
	draw_map(game);
	draw_wall(game);
}
