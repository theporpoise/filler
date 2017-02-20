/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:32:02 by mgould            #+#    #+#             */
/*   Updated: 2017/02/20 11:41:22 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <filler.h>
#include <stdlib.h>
#include <unistd.h>
//
#include <stdio.h>

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

	//fprintf(stderr, "\npickpiece 0");
	gv = -1;
	tmp = 0;
	ret = game->safelist;
	//fprintf(stderr, "pickpiece 1");
	//fprintf(stderr, "pickpiece 2");
	pickpiece = ret;
	//fprintf(stderr, "pickpiece 3");
	while (pickpiece)
	{
		//fprintf(stderr, "in while pickpiece 4");
		tmp = pointvalue(*game, pickpiece);
		pickpiece->score = tmp;
		if (tmp > gv)
		{
			gv = tmp;
			ret = pickpiece;
		}
		//fprintf(stderr, "pickpiece past while loop");
		pickpiece = pickpiece->next;
	}
	return (ret);
}

/*
** debug_game(game);
*/

void	placement(t_game *game)
{
	t_point *placement;


	//fprintf(stderr, "placement 0");
	placement = NULL;
	//fprintf(stderr, "placement 1");
	getsafelist(game);
	//fprintf(stderr, "placement 2");
	//getsafelist(game, &(game->safelist));
	mapvalue(game);
	//fprintf(stderr, "placement 3");
	placement = pickpiece(game);
	//fprintf(stderr, "placement 4");
	ft_putnbr(placement->x);
	ft_putstr(" ");
	ft_putnbr(placement->y);
	ft_putstr("\n");
	//ft_printf("%d %d\n", placement->x, placement->y);
	//fprintf(stderr, "placement 5");
	//debug_game(game);
}

/*
** usleep (100000);
*/

int		main(void)
{
	t_game		game;
	char		*line;

	game_init(&game);
	while (get_next_line(0, &line))
	{
		//fprintf(stderr, "step 1");
		if (parse(&game, line))
		{
			//
			//fprintf(stderr, "step 2");
			//fprintf(stderr, "step 3");
			placement(&game);
			//fprintf(stderr, "step 4");
			//debug_game(&game);
			//fprintf(stderr, "end");
			//usleep(100000);
		}
	}
}
