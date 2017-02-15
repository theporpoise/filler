#include <libft.h>
#include <filler.h>
#include <stdio.h>
#include <stdlib.h>

void	game_init(t_game *game)
{
	int *spot;

	spot = (int *)malloc(sizeof(int) * 2);
	spot[0] = 0;
	spot[1] = 0;

	game->player = -1;
	game->ox = 'Z';
	game->map_x = -1;
	game->map_y = -1;
	game->map = NULL;
	game->p_x = -1;
	game->p_y = -1;
	game->piece = NULL;
	game->safelist = NULL;
	game->spot = spot;
}

void	pointinit(t_point **point_pointer, int x, int y)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	point->next = NULL;

	*point_pointer = point;
}

int notinbounds(t_game *game, t_point *point)
{
	if (game->map_x <= (point->x + game->spot[0]))
		return (1);
	else if (game->map_y <= (point->y + game->spot[1]))
		return (1);
	return (0);
}

int	is_safe_point(char **map, char **piece, t_point *point, t_game *game)
{
	int overlap;

	overlap = 0;
	game->spot[0] = 0;
	while (piece[game->spot[0]])
	{
		game->spot[1] = 0;
		while (piece[game->spot[0]][game->spot[1]] && overlap < 2)
		{
			if (notinbounds(game, point))
			{
				overlap += 2;
			}
			else if (piece[game->spot[0]][game->spot[1]] == '.')
				;
			else if (ft_tolower(map[point->x + game->spot[0]][point->y + \
				game->spot[1]]) == game->ox  && \
				piece[game->spot[0]][game->spot[1]] == '*')
			{
				overlap++;
			}
			else if (ft_tolower(map[point->x + game->spot[0]][point->y + \
				game->spot[1]]) != '.')
			{
				overlap += 2;
			}
			game->spot[1]++;
		}
		game->spot[0]++;
	}
	return (overlap);
}

//suggest starting here and cleaning this fucntion up.

t_point	*getsafelist(t_game *game, t_point *begin)
{
	int		i;
	int		j;
	t_point *start;
	t_point	*next;

	start = NULL;
	next = NULL;
	pointinit(&start, -1, -1);
	begin = start;
	i = 0;
	while (i < game->map_x)
	{
		j = 0;
		while (j < game->map_y)
		{
			pointinit(&next, i, j);
			if (is_safe_point(game->map, game->piece, next, game) == 1)
			{
				start->next = next;
				start = start->next;
			}
			else
				free(next);
			j++;
		}
		i++;
	}
	if (begin->x == -1 && begin->next)
	{
		next = begin;
		begin = begin->next;
		free(next);
	}
	return (begin);
}

void	placement(t_game *game)
{
	t_point *begin;

	begin = NULL;
	game->safelist = getsafelist(game, begin);
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
}



/*
//step 2
//creeate simple map weight, reads map and updates chars to #
//step 3
//calculate value at each placement.  if update is post point check, then
//no need to modify point check
//step 4
//place highest value piece
//fprintf(stderr, "you got here");
//ft_putstr_fd("loopy\n", 2);
// is safe?
// -all places where you can place a piece
// return top placement
// -rank placement
//print_move
//
//

fprintf(stderr, "YOU GOT IN THE opponent match\n");
				fprintf(stderr, "pointx: %d, pointy: %d", point->x, point->y);
				fprintf(stderr, "spotx: %d, spoty: %d\n", game->spot[0], game->spot[1]);



fprintf(stderr, "YOU GOT IN THE RETURN\n");
		fprintf(stderr, "pointx: %d, pointy: %d", point->x, point->y);


*/
