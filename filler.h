/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:36:16 by mgould            #+#    #+#             */
/*   Updated: 2017/02/13 20:22:10 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_game
{
	int				player;
	char			ox;
	int				map_x;
	int				map_y;
	char			**map;
	int				p_x;
	int				p_y;
	char			**piece;
	int				**territory;
}					t_game;

int					parse(t_game *game, char *line);

// debug functions
void	debug_printmap(char **map, FILE *fp);
void	debug_printpiece(char **map, FILE *fp);
void	debug_game(t_game *game);

#endif
