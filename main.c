/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 08:37:31 by mgould            #+#    #+#             */
/*   Updated: 2017/02/08 15:21:52 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main(void)
{
	int i;
	char buf[2];

	i = 0;
	while ((i = read(0, buf, 1)))
	{
		//ft_putchar(buf[0]);
		ft_putstr(" 8 2\n");
	}

	//while get next line
	//read in
	//return piece position  when appropriate
	//do stuff
	//when fin break
}
