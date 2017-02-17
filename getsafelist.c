/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getsafelist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:45:55 by mgould            #+#    #+#             */
/*   Updated: 2017/02/16 17:06:03 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <filler.h>
#include <stdlib.h>

static int	notinbounds(t_game *game, t_point *point)
{
	if (game->map_x <= (point->x + game->spot[0]))
		return (1);
	else if (game->map_y <= (point->y + game->spot[1]))
		return (1);
	return (0);
}

static int	calcover(t_game *game, t_point *point, char **map, char **piece)
{
	int overlap;

	overlap = 0;
	if (piece[game->spot[0]][game->spot[1]] == '.')
		;
	else if (notinbounds(game, point))
	{
		overlap += 2;
	}
	else if (piece[game->spot[0]][game->spot[1]] == '.')
		;
	else if (ft_tolower(map[point->x + game->spot[0]][point->y + \
		game->spot[1]]) == game->ox && \
		piece[game->spot[0]][game->spot[1]] == '*')
	{
		overlap++;
	}
	else if (ft_tolower(map[point->x + game->spot[0]][point->y + \
		game->spot[1]]) != '.')
	{
		overlap += 2;
	}
	return (overlap);
}

static int	safe_point(char **map, char **piece, t_point *point, t_game *game)
{
	int overlap;

	overlap = 0;
	game->spot[0] = 0;
	while (piece[game->spot[0]])
	{
		game->spot[1] = 0;
		while (piece[game->spot[0]][game->spot[1]] && overlap < 2)
		{
			overlap += calcover(game, point, map, piece);
			game->spot[1]++;
		}
		game->spot[0]++;
	}
	return (overlap);
}

void		getsafelist(t_game *game, t_point **begin)
{
	int		i;
	int		j;
	t_point *start;
	t_point	*next;

	start = pointinit(-1, -1);
	*begin = start;
	i = -1;
	while (++i < game->map_x)
	{
		j = -1;
		while (++j < game->map_y)
		{
			next = pointinit(i, j);
			if (safe_point(game->map, game->piece, next, game) == 1)
			{
				start->next = next;
				start = start->next;
			}
			else
				free(next);
		}
	}
}
