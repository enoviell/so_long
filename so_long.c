/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:03:12 by enoviell          #+#    #+#             */
/*   Updated: 2023/03/02 11:59:29 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	argv_check(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e'
		&& argv[i - 2] == 'b' && argv[i - 3] == '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		if (map_check(&game) && argv_check(argv[1]))
		{
			init_game(&game);
			gameplay(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			if (game.map)
				free_map(game.map);
			ft_putstr("Error\nInvalid Map");
			exit(1);
		}
	}
	else
	{
		ft_putstr("Error\nInvalid Sytax");
		exit(1);
	}
	return (0);
}
