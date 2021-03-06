# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgould <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/12 11:00:36 by mgould            #+#    #+#              #
#    Updated: 2017/02/20 15:19:03 by mgould           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

CFLAGS = -Wall -Wextra -Werror -I $(LIBRARY) -I .

OBJCS = main.o parse.o getsafelist.o structinit.o aoe.o \
		inbounds.o print_heatmap.o

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
# to debug need to include debug.o
