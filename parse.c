#include <libft.h>
#include <filler.h>
#include <stdio.h>
#include <stdlib.h>


static void	get_player_and_piece(t_game *game, char *line)
{
	game->player = line[10] - '0';
	if (game->player == 1)
		game->ox = 'o';
	else
		game->ox = 'x';
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
		game->map[i] = (char *)ft_memalloc(game->map_y + 2);
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
	if (game->piece)
	{
		while (game->piece[i])
		{
			ft_bzero(&(game->piece[i]), ft_strlen(game->piece[i]));
			ft_strdel(&(game->piece[i]));
			i++;
		}
		free(game->piece);
	}
	i = 0;
	game->piece = (char **)malloc(sizeof(char *) * (game->p_x + 1));
	game->piece[game->p_x] = NULL;
	while (i < game->p_x)
	{
		game->piece[i] = (char *)ft_memalloc(game->p_y + 2);
		i++;
	}
}

static void	copy_map(t_game *game, char *line, int *count)
{
	ft_strcpy(game->map[*count], (line + 4));
	game->map[*count][game->map_y] = '\n';
	game->map[*count][game->map_y + 1] = '\0';
	*count += 1;
}

int		parse(t_game *game, char *line)
{
	static int	count;

	if (!(strncmp("$$$", line, 3)) && ft_strstr(line, "matt"))
		get_player_and_piece(game, line);
	else if (!(strncmp("Plateau", line, 7)) && game->map == NULL)
		map_size_and_map(game, line);
	else if (ft_isdigit(*line))
	{
		copy_map(game, line, &count);
	}
	else if (!(strncmp("Piece", line, 5)))
		get_piece_size(game, line, &count);
	else if ((*line == '*' || *line == '.'))
	{
		game->piece[count] = ft_strdup(line);
		game->piece[count][game->p_y] = '\n';
		count++;
		if (count == game->p_x)
		{
			count = 0;
			return (1);
		}
	}
	return (0);
}



