/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_heatmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:25:03 by mgould            #+#    #+#             */
/*   Updated: 2017/02/20 14:43:32 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	print_heatmap(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '3')
				ft_putchar_color_fd(map[i][j], 1, 2);
			else if (map[i][j] == '2')
				ft_putchar_color_fd(map[i][j], 2, 2);
			else if (map[i][j] == '1')
				ft_putchar_color_fd(map[i][j], 3, 2);
			else
				ft_putchar_color_fd(map[i][j], 0, 2);
			j++;
		}
		ft_putchar_fd('\n', 2);
		i++;
	}
}
