/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:28:05 by mgould            #+#    #+#             */
/*   Updated: 2017/02/20 11:50:37 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <filler.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	debug_printmap(char **map, FILE *fp)
{
	int i;

	i = 0;
	while (map[i])
	{
		fprintf(fp, "%.3d %s\n", i, map[i]);
		i++;
	}
}

static void	debug_printpiece(char **map, FILE *fp)
{
	int i;

	i = 0;
	while (map[i])
	{
		fprintf(fp, "%s\n", map[i]);
		i++;
	}
}

static void	debug_safelist(t_point *point, FILE *fp)
{
	while (point)
	{
		fprintf(fp, "SafeListWhile\n");
		fprintf(fp, "X:%d, Y:%d, Score:%d\n", point->x, point->y, point->score);
		point = point->next;
	}
}

void		debug_game(t_game *game)
{
	FILE *fp;

	fp = fopen("file.txt", "a+");
	fprintf(fp, "player:%d\n", game->player);
	fprintf(fp, "ox    :%c\n", game->ox);
	fprintf(fp, "map_x :%d\n", game->map_x);
	fprintf(fp, "map_y :%d\n", game->map_y);
	fprintf(fp, "p_x   :%d\n", game->p_x);
	fprintf(fp, "p_y   :%d\n", game->p_y);
	debug_printpiece(game->piece, fp);
	debug_printmap(game->map, fp);
	debug_safelist(game->safelist, fp);
	debug_printpiece(game->piece, fp);
	fclose(fp);
}
/*
** fprintf(fp, "player:%d\n", game->player);
** fp = fopen("file.txt", "w+");
** fprintf(fp, "ox    :%c\n", game->ox);
** fprintf(fp, "map_x :%d\n", game->map_x);
** fprintf(fp, "map_y :%d\n", game->map_y);
** fprintf(fp, "p_x   :%d\n", game->p_x);
** fprintf(fp, "p_y   :%d\n", game->p_y);
** debug_printpiece(game->piece, fp);
*/
