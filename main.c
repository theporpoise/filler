#include <libft.h>
#include <filler.h>
#include <stdio.h>
#include <stdlib.h>

void	startposition(t_game *game)
{
	game->spot[0] = 0;
	while (game->map[game->spot[0]])
	{
		game->spot[1] = 0;
		while (game->map[game->spot[0]][game->spot[1]])
		{
			if (game->map[game->spot[0]][game->spot[1]] == '.')
				;
			else if (game->map[game->spot[0]][game->spot[1]] == \
					ft_toupper(game->ox))
			{
				game->start[0] = game->spot[0];
				game->start[1] = game->spot[1];
			}
			else
			{
				game->start[2] = game->spot[0];
				game->start[3] = game->spot[1];
			}
			game->spot[1] += 1;
		}
		game->spot[0] += 1;
	}
}

static int	inbounds(t_game *game, int i, int j)
{

	if (i < 0 || j >= game->map_y || i >= game->map_x || j < 0)
	{
		//fprintf(stderr, "YOU are out of bounds\n");
		return (0);
	}
	if (game->map[i][j] == ft_toupper(game->oox) || game->map[i][j] == game->oox)
	{
		//fprintf(stderr, "YOU GOT IN matches oppoennt\n");
		return (0);
	}
	if (!ft_isdigit(game->map[i][j]))
	{
		//fprintf(stderr, "IS not a digit DIGIT\n");
		game->map[i][j] = '0';
	}

	return (1);
}

/*
instead of using this i can run through whole map and set pieces next to a 3
and equal to zero to equal a 2. can do the same for 2 and 3 :-).
*/

char	affectsetter(int a)
{
	char	ret;

	ret = '0';
	if (a == 4)
		ret += 2;
	else if (a == 5)
		ret += 1;
	else if (a == 6)
		ret = '1';
	else
		ret += a;
	return (ret);
}

void	aroundpoint1(t_game *game, int i, int j, char affect)
{

	if (inbounds(game, (i - 1), j) && game->map[i - 1][j] == '0')
		game->map[i - 1][j] = affect;
	if (inbounds(game, (i + 1), j) && game->map[i + 1][j] == '0')
		game->map[i + 1][j] = affect;
	if (inbounds(game, (i), (j - 1)) && game->map[i][j -1 ] == '0')
		game->map[i][j - 1] = affect;
	if (inbounds(game, i, (j + 1)) && game->map[i][j + 1] == '0')
		game->map[i][j + 1] = affect;
	if (inbounds(game, (i + 1), (j + 1)) && game->map[i + 1][j + 1] == '0')
		game->map[i + 1][j + 1] = affect;
	if (inbounds(game, (i + 1), (j - 1)) && game->map[i + 1][j - 1] == '0')
		game->map[i + 1][j - 1] = affect;
	if (inbounds(game, (i - 1), (j - 1)) && game->map[i - 1][j - 1] == '0')
		game->map[i - 1][j - 1] = affect;
	if (inbounds(game, (i - 1), (j + 1)) && game->map[i - 1][j + 1] == '0')
		game->map[i - 1][j + 1] = affect;

}

void	aroundpoint2(t_game *game, int i, int j, int a)
{
	char	affect;
	char	m;

	affect = affectsetter(a);
	m = '0' + a - 1;
	if (inbounds(game, (i - 1), j) && game->map[i - 1][j] == m)
		game->map[i][j] = affect;
	else if (inbounds(game, (i + 1), j) && game->map[i + 1][j] == m)
		game->map[i][j] = affect;
	else if (inbounds(game, (i), (j - 1)) && game->map[i][j -1 ] == m)
		game->map[i][j] = affect;
	else if (inbounds(game, i, (j + 1)) && game->map[i][j + 1] == m)
		game->map[i][j] = affect;
	else if (inbounds(game, (i + 1), (j + 1)) && game->map[i + 1][j + 1] == m)
		game->map[i][j] = affect;
	else if (inbounds(game, (i + 1), (j - 1)) && game->map[i + 1][j - 1] == m)
		game->map[i][j] = affect;
	else if (inbounds(game, (i - 1), (j - 1)) && game->map[i - 1][j - 1] == m)
		game->map[i][j] = affect;
	else if (inbounds(game, (i - 1), (j + 1)) && game->map[i - 1][j + 1] == m)
		game->map[i][j] = affect;
	}


void	aoe1(t_game *game, int a)
{
	int i;
	int j;
	char affect;

	affect = affectsetter(a);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '.' || game->map[i][j] == ft_toupper(game->ox))
				game->map[i][j] = '0';
			else if (game->map[i][j] == ft_toupper(game->oox))
				aroundpoint1(game, i, j, affect);
			j++;
		}
		i++;
	}

}

void	aoe2(t_game *game, int a)
{
	int i;
	int j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '0')
				aroundpoint2(game, i, j, a);
			j++;
		}
		i++;
	}

}


void	mapvalue(t_game *game)
{

	aoe1(game, 1);
	aoe2(game, 2);
	aoe2(game, 3);
	aoe2(game, 4);
	aoe2(game, 5);
// this is broke as fuck b/c the numbers are counting down aoe2(game, 6);

}

void	placement(t_game *game)
{
	static int	i;

	i++;
	if (i == 1)
		startposition(game);
	getsafelist(game, &(game->safelist));
	mapvalue(game);

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
			//create calculate value function
			//go through list, calculate value, return highest value
			//print out with ft_printf("%d %d\n", x, y);
			//play it!
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
