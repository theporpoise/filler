/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 17:07:31 by mgould            #+#    #+#             */
/*   Updated: 2017/02/17 15:03:07 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <filler.h>
#include <stdlib.h>

static void	get_player_and_piece(t_game *game, char *line)
{
	game->player = line[10] - '0';
	if (game->player == 1)
	{
		game->ox = 'o';
		game->oox = 'x';
	}
	else
	{
		game->ox = 'x';
		game->oox = 'o';
	}
}

static void	map_size_and_map(t_game *game, char *line)
{
	int i;

	i = 0;
	game->map_x = ft_atoi(line + 8);
	game->map_y = ft_atoi(line + 8 + ft_strlen(ft_itoa(game->map_x)));
	game->map = (char **)malloc(sizeof(char *) * (game->map_x + 1));
	game->map[game->map_x] = NULL;
	while (i < game->map_x)
	{
		game->map[i] = (char *)ft_memalloc(game->map_y);
		i++;
	}
}

static void	get_piece_size(t_game *game, char *line, int *count)
{
	int i;

	i = 0;
	*count = 0;
	game->p_x = ft_atoi(line + 6);
	game->p_y = ft_atoi(line + 6 + ft_strlen(ft_itoa(game->p_x)));
	game->piece = (char **)malloc(sizeof(char *) * (game->p_x + 1));
	game->piece[game->p_x] = NULL;
	while (i < game->p_x)
	{
		game->piece[i] = (char *)ft_memalloc(game->p_y + 1);
		ft_bzero(game->piece[i], game->p_y + 1);
		i++;
	}
}

static void	copy_map(t_game *game, char *line, int *count)
{
	ft_strcpy(game->map[*count], (line + 4));
	game->map[*count][game->map_y] = '\0';
	*count += 1;
}

int			parse(t_game *game, char *line)
{
	static int	count;

	if (!(strncmp("$$$", line, 3)) && ft_strstr(line, "../filler"))
		get_player_and_piece(game, line);
	else if (!(strncmp("Plateau", line, 7)) && game->map == NULL)
		map_size_and_map(game, line);
	else if (ft_isdigit(*line))
		copy_map(game, line, &count);
	else if (!(strncmp("Piece", line, 5)))
		get_piece_size(game, line, &count);
	else if ((*line == '*' || *line == '.'))
	{
		game->piece[count] = ft_strdup(line);
		count++;
		if (count == game->p_x)
		{
			count = 0;
			return (1);
		}
	}
	return (0);
}
