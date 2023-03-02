/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:22:47 by enoviell          #+#    #+#             */
/*   Updated: 2023/02/27 17:12:46 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	rectangular(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}

static int	wall(char **map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (map[i])
		i++;
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	is_validate(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'K')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	pce_control(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->n_collect = 0;
	game->n_player = 0;
	game->n_exit = 0;
	while (game -> map[i])
	{
		j = 0;
		while (game -> map[i][j] != '\0')
		{
			if (game -> map[i][j] == 'P')
				game -> n_player++;
			if (game -> map[i][j] == 'E')
				game -> n_exit++;
			if (game -> map[i][j] == 'C')
				game -> n_collect++;
			j++;
		}
		i++;
	}
	if (game -> n_player != 1 || game -> n_exit == 0 || game -> n_collect == 0)
		return (0);
	return (1);
}

int	map_check(t_game *game)
{
	if (rectangular(game->map) && wall(game->map)
		&& is_validate(game->map) && (pce_control(game)))
		return (1);
	return (0);
}
