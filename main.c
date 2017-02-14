#include <libft.h>
#include <filler.h>
#include <stdio.h>
#include <stdlib.h>

void	game_init(t_game *game)
{
	game->player = -1;
	game->ox = 'Z';
	game->map_x = -1;
	game->map_y = -1;
	game->map = NULL;
	game->p_x = -1;
	game->p_y = -1;
	game->piece = NULL;
	game->territory = NULL;
}


int	**territory(t_game *game)
{
	int **area;
	int i;
	int j;

	i = 0;
	area = ft_memalloc(sizeof(int *) * (game->map_x + 1));
	area[game->map_x] = NULL;
	while (i < game->map_x)
	{
		area[i] = ft_memalloc(sizeof(int) * (game->map_y + 1));
		j = 0;
		while (j < game->map_y)
		{
			if (game->map[i][j] == game->ox || game->map[i][j] == (game->ox - ('a' - 'A')))
				area[i][j] = 1;
			else if (game->map[i][j] != 0)
				area[i][j] = 2;
			else
				area[i][j] = 0;
			j++;
		}
		i++;
	}
	return (area);
}

//split out creation function for ints and then population function?
//only dups once, but otherwise it's good.

/*
void	is_safe(t_game *game)
{
	;
}
*/

void	placement(t_game *game)
{

	game->territory = territory(game);

}




int main(void)
{
	t_game		game;
	char		*line;

	game_init(&game);
	while (get_next_line(0, &line))
	{
		if (parse(&game, line))
		{
			placement(&game);
			debug_game(&game);
		}
	}
	//ft_putstr_fd("loopy\n", 2);
	// is safe?
	// -all places where you can place a piece
	// return top placement
	// -rank placement
	//print_move


}













