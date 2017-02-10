# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgould <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/12 11:00:36 by mgould            #+#    #+#              #
#    Updated: 2017/02/10 12:23:52 by mgould           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = resources/players/matt_filler

CFLAGS = -Wall -Wextra -Werror -I $(LIBRARY)

OBJCS = main.o

LIBFT = /nfs/2016/m/mgould/thelibrary/libft.a

LIBRARY = /nfs/2016/m/mgould/thelibrary/

all: $(NAME)

$(NAME): $(OBJCS) $(LIBFT)
	gcc $(CFLAGS) -o $@ $^

$(LIBFT):
	cd $(LIBRARY) && $(MAKE)

clean:
	rm -f $(OBJCS)
	cd $(LIBRARY) && make fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

.PHONY: clean re fclean
