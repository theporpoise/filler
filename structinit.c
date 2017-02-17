/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:49:49 by mgould            #+#    #+#             */
/*   Updated: 2017/02/17 08:41:55 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <filler.h>
#include <stdlib.h>

void	game_init(t_game *game)
{
	int *spot;
	int *start;

	spot = (int *)malloc(sizeof(int) * 2);
	start = (int *)malloc(sizeof(int) * 4);
	spot[0] = 0;
	spot[1] = 0;
	start[0] = 0;
	start[1] = 0;
	start[2] = 0;
	start[3] = 0;
	game->player = -1;
	game->ox = 'Z';
	game->oox = 'Z';
	game->map_x = -1;
	game->map_y = -1;
	game->map = NULL;
	game->p_x = -1;
	game->p_y = -1;
	game->piece = NULL;
	game->safelist = NULL;
	game->spot = spot;
	game->start = start;
}

t_point	*pointinit(int x, int y)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	point->score = 0;
	point->next = NULL;
	return (point);
}
