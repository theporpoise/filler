/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:36:16 by mgould            #+#    #+#             */
/*   Updated: 2017/02/18 16:08:13 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_point
{
	int				x;
	int				y;
	int				score;
	struct s_point	*next;
}					t_point;

typedef struct		s_game
{
	int				player;
	char			ox;
	char			oox;
	int				map_x;
	int				map_y;
	char			**map;
	int				p_x;
	int				p_y;
	char			**piece;
	t_point			*safelist;
	int				*spot;
	int				*start;
}					t_game;

int					parse(t_game *game, char *line);
void				getsafelist(t_game *game); //, t_point **begin);
void				game_init(t_game *game);
t_point				*pointinit(int x, int y);
void				aoe1(t_game *game, int a);
void				aoe2(t_game *game, int a);
int					inbounds(t_game *game, int i, int j);
/*
** Debug Functions
*/
void				debug_game(t_game *game);
#endif
