/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:32:02 by mgould            #+#    #+#             */
/*   Updated: 2017/02/20 15:06:00 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <filler.h>
#include <stdlib.h>
#include <unistd.h>

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

t_point	*pickpiece(t_game *game)
{
	t_point *pickpiece;
	t_point *ret;
	int		gv;
	int		tmp;

	gv = -1;
	tmp = 0;
	ret = game->safelist;
	pickpiece = ret;
	while (pickpiece)
	{
		tmp = pointvalue(*game, pickpiece);
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
	getsafelist(game);
	mapvalue(game);
	placement = pickpiece(game);
	ft_putnbr(placement->x);
	ft_putstr(" ");
	ft_putnbr(placement->y);
	ft_putstr("\n");
}

/*
** to slow down output for corrections use usleep (100000);
** use print_heatmap(game->map); below placement for corrections
*/

int		main(void)
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
