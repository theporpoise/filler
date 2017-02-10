#include <libft.h>
#include <stdio.h>

// may make a map and a piece struct as things develop.

typedef struct	s_state;
{
	int		player;
	char	marker;
	char	**map;
	char	**piece;
}				t_state;


void	parse(t_state *state)
{



}

int main(void)
{
	t_state	state;
	char	*line;


	while (get_next_line(0, &line))
	{
		if (!(strncmp("$$$", line, 3)))
		{
			ft_putstr("8 2\n");
		}
	}


}
