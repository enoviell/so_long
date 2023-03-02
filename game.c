/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:32:35 by enoviell          #+#    #+#             */
/*   Updated: 2023/02/27 16:49:56 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	button(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->yp -= 1;
		player_w(game);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->xp -= 1;
		player_a(game);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->yp += 1;
		player_s(game);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->xp += 1;
		player_d(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit_game(game);
	else if (!game->endgame)
		button(keycode, game);
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, keypress, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
	mlx_hook(game->win, 9, 1L << 21, draw_map, game);
	mlx_hook(game->win, 9, 1L << 21, draw_wall, game);
	mlx_loop_hook(game->mlx, animation, game);
}
