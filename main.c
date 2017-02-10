#include <libft.h>
#include <stdio.h>
#include <stdlib.h>

// may make a map and a piece struct as things develop.

typedef struct	s_game
{
	int		player;
	char	ox;
	int		map_x;
	int		map_y;
	char	**map;
	char	**piece;
}				t_game;

void	printmap(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		fprintf(stderr, "%.3d %s", i, map[i]);
		i++;
	}
}

void	debug_game(t_game *game)
{

		fprintf(stderr, "player:%d\n", game->player);
		fprintf(stderr, "ox    :%c\n", game->ox);
		fprintf(stderr, "map_x :%d\n", game->map_x);
		fprintf(stderr, "map_y :%d\n", game->map_y);
		printmap(game->map);
}

void	parse(t_game *game, char *line)
{
	int			i;
	static int	count;

	if (!count)
		count = 0;
	i = 0;
	if (!(strncmp("$$$", line, 3)) && ft_strstr(line, "matt"))
	{
		game->player = line[10] - '0';
		if (game->player == 1)
			game->ox = 'o';
		else
			game->ox = 'x';
	}
	else if (!(strncmp("Plateau", line, 7)))
	{
		game->map_x = ft_atoi(line + 8);
		game->map_y = ft_atoi(line + 8 + ft_strlen(ft_itoa(game->map_x)));
		game->map = (char **)malloc(sizeof(char *) * (game->map_x + 1));
		while (i < game->map_x)
		{
			game->map[i] = (char *)ft_memalloc(game->map_y + 1);
			game->map[i] = (char*)ft_memset(game->map[i], '.', game->map_y);
			i++;
		}
	}
	else if (ft_isdigit(*line))
	{
		ft_strcpy(game->map[count], (line + 4));
		game->map[count][game->map_y] = '\n';
		count++;
	}
	else if (!(strncmp("Piece", line, 5)))
	{
		count = 0;
		debug_game(game);
	}
}

int main(void)
{
	t_game		game;
	char		*line;

	while (get_next_line(0, &line))
	{
		parse(&game, line);

	}


}
