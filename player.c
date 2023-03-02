/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:37:44 by enoviell          #+#    #+#             */
/*   Updated: 2023/03/01 19:31:36 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_update(char key, t_game *game)
{
	if (key == 'w')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"images/ashup.xpm", &game->img_w, &game->img_h);
	if (key == 'a')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"images/ashleft.xpm", &game->img_w, &game->img_h);
	if (key == 's')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"images/ashdown.xpm", &game->img_w, &game->img_h);
	if (key == 'd')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"images/ashright.xpm", &game->img_w, &game->img_h);
}

void	player_w(t_game *game)
{
	player_update('w', game);
	if (game->map[game->yp][game->xp]
		== 'E' && game->n_collect == 0)
		win_w(game);
	else if (game->map[game->yp][game->xp] == 'K')
		draw_tomb(game);
	else if (game->map[game->yp][game->xp] == 'E'
		|| game->map[game->yp][game->xp] == '1')
	game->yp += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->yp][game->xp] == 'C')
				game->n_collect -= 1;
		game->map[game->yp][game->xp] = 'P';
		game->map[game->yp + 1][game->xp] = '0';
		game->moves++;
		display_term(game);
		draw_map(game);
		draw_wall(game);
	}
}

void	player_a(t_game *game)
{
	player_update('a', game);
	if (game->map[game->yp][game->xp]
		== 'E' && game->n_collect == 0)
		win_a(game);
	else if (game->map[game->yp][game->xp] == 'K')
		draw_tomb(game);
	else if (game->map[game->yp][game->xp] == 'E'
		|| game->map[game->yp][game->xp] == '1')
	game->xp += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->yp][game->xp] == 'C')
				game->n_collect -= 1;
		game->map[game->yp][game->xp] = 'P';
		game->map[game->yp][game->xp + 1] = '0';
		game->moves++;
		display_term(game);
		draw_map(game);
		draw_wall(game);
	}
}

void	player_s(t_game *game)
{
	player_update('s', game);
	if (game->map[game->yp][game->xp]
		== 'E' && game->n_collect == 0)
		win_s(game);
	else if (game->map[game->yp][game->xp] == 'K')
		draw_tomb(game);
	else if (game->map[game->yp][game->xp] == 'E'
		|| game->map[game->yp][game->xp] == '1')
	game->yp -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->yp][game->xp] == 'C')
				game->n_collect -= 1;
		game->map[game->yp][game->xp] = 'P';
		game->map[game->yp - 1][game->xp] = '0';
		game->moves++;
		display_term(game);
		draw_map(game);
		draw_wall(game);
	}
}

void	player_d(t_game *game)
{
	player_update('d', game);
	if (game->map[game->yp][game->xp]
		== 'E' && game->n_collect == 0)
		win_d(game);
	else if (game->map[game->yp][game->xp] == 'K')
		draw_tomb(game);
	else if (game->map[game->yp][game->xp] == 'E'
		|| game->map[game->yp][game->xp] == '1')
			game->xp -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->yp][game->xp] == 'C')
				game->n_collect -= 1;
		game->map[game->yp][game->xp] = 'P';
		game->map[game->yp][game->xp - 1] = '0';
		game->moves++;
		display_term(game);
		draw_map(game);
		draw_wall(game);
	}
}
