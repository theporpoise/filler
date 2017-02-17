/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inbounds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 13:20:38 by mgould            #+#    #+#             */
/*   Updated: 2017/02/17 14:35:56 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <filler.h>
#include <stdlib.h>

int	inbounds(t_game *game, int i, int j)
{
	if (i < 0 || j >= game->map_y || i >= game->map_x || j < 0)
	{
		return (0);
	}
	if (game->map[i][j] == ft_toupper(game->oox) || \
		game->map[i][j] == game->oox)
	{
		return (0);
	}
	if (game->map[i][j] == '.')
	{
		game->map[i][j] = '0';
	}
	return (1);
}
