#include <libft.h>
#include <filler.h>
#include <stdio.h>
#include <stdlib.h>
// include unistd for sleeping
#include <unistd.h>


static int	inbounds(t_game *game, int i, int j)
{

	if (i < 0 || j >= game->map_y || i >= game->map_x || j < 0)
	{
		return (0);
	}
	if (game->map[i][j] == ft_toupper(game->oox) || game->map[i][j] == game->oox)
	{
		return (0);
	}
	if (game->map[i][j] == '.')
	{
		game->map[i][j] = '0';
	}

	return (1);
}

char	affectsetter(int a)
{
	char	ret;

	ret = '0';
	if (a == 4)
		ret += 2;
	else if (a == 5)
		ret += 1;
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
	m = affectsetter(a - 1);
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
			if (game->map[i][j] == '.')
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
}


int		pointvalue(t_game game, t_point *point)
{
	int	value;
	int	i;
	int	j;

	value = 0;
	i = -1;
	if (point->x == -1)
		return (-1);
	while (game.piece[++i])
	{
		j = -1;
		while (game.piece[i][++j])
		{
			if (inbounds(&game, (point->x + i), (point->y + j)) && \
				ft_isdigit(game.map[point->x + i][point->y + j]))
				value += (game.map[point->x + i][point->y + j]) - '0';
		}
	}
	return (value);
}


t_point	*pickpiece(t_game game)
{
	t_point *pickpiece;
	t_point *ret;
	int		gv;
	int		tmp;

	gv = -1;
	tmp = 0;
	ret = game.safelist;
	pickpiece = game.safelist;

	while (pickpiece)
	{
		tmp = pointvalue(game, pickpiece);
		pickpiece->score = tmp;
		if (tmp > gv)
		{
			gv = tmp;
			ret = pickpiece;
		}
		pickpiece = pickpiece->next;
	}
	return (ret);
}

void	placement(t_game *game)
{
	t_point *placement;

	placement = NULL;
	getsafelist(game, &(game->safelist));
	mapvalue(game);
	placement = pickpiece(*game);
	ft_printf("%d %d\n", placement->x, placement->y);

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
		}
	}
}
