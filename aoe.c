/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aoe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 13:12:55 by mgould            #+#    #+#             */
/*   Updated: 2017/02/17 14:35:18 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <filler.h>
#include <stdlib.h>

static char	affectsetter(int a)
{
	char	ret;

	ret = '0';
	if (a == 4)
		ret += 2;
	else if (a == 5)
		ret += 1;
	else
		ret += a;
	return (ret);
}

static void	aroundpoint1(t_game *game, int i, int j, char affect)
{
	if (inbounds(game, (i - 1), j) && game->map[i - 1][j] == '0')
		game->map[i - 1][j] = affect;
	if (inbounds(game, (i + 1), j) && game->map[i + 1][j] == '0')
		game->map[i + 1][j] = affect;
	if (inbounds(game, (i), (j - 1)) && game->map[i][j - 1] == '0')
		game->map[i][j - 1] = affect;
	if (inbounds(game, i, (j + 1)) && game->map[i][j + 1] == '0')
		game->map[i][j + 1] = affect;
	if (inbounds(game, (i + 1), (j + 1)) && game->map[i + 1][j + 1] == '0')
		game->map[i + 1][j + 1] = affect;
	if (inbounds(game, (i + 1), (j - 1)) && game->map[i + 1][j - 1] == '0')
		game->map[i + 1][j - 1] = affect;
	if (inbounds(game, (i - 1), (j - 1)) && game->map[i - 1][j - 1] == '0')
		game->map[i - 1][j - 1] = affect;
	if (inbounds(game, (i - 1), (j + 1)) && game->map[i - 1][j + 1] == '0')
		game->map[i - 1][j + 1] = affect;
}

static void	aroundpoint2(t_game *game, int i, int j, int a)
{
	char	affect;
	char	m;

	affect = affectsetter(a);
	m = affectsetter(a - 1);
	if (inbounds(game, (i - 1), j) && game->map[i - 1][j] == m)
		game->map[i][j] = affect;
	else if (inbounds(game, (i + 1), j) && game->map[i + 1][j] == m)
		game->map[i][j] = affect;
	else if (inbounds(game, (i), (j - 1)) && game->map[i][j - 1] == m)
		game->map[i][j] = affect;
	else if (inbounds(game, i, (j + 1)) && game->map[i][j + 1] == m)
		game->map[i][j] = affect;
	else if (inbounds(game, (i + 1), (j + 1)) && game->map[i + 1][j + 1] == m)
		game->map[i][j] = affect;
	else if (inbounds(game, (i + 1), (j - 1)) && game->map[i + 1][j - 1] == m)
		game->map[i][j] = affect;
	else if (inbounds(game, (i - 1), (j - 1)) && game->map[i - 1][j - 1] == m)
		game->map[i][j] = affect;
	else if (inbounds(game, (i - 1), (j + 1)) && game->map[i - 1][j + 1] == m)
		game->map[i][j] = affect;
}

void		aoe1(t_game *game, int a)
{
	int		i;
	int		j;
	char	affect;

	affect = affectsetter(a);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '.')
				game->map[i][j] = '0';
			else if (game->map[i][j] == ft_toupper(game->oox))
				aroundpoint1(game, i, j, affect);
			j++;
		}
		i++;
	}
}

void		aoe2(t_game *game, int a)
{
	int i;
	int j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '0')
				aroundpoint2(game, i, j, a);
			j++;
		}
		i++;
	}
}
