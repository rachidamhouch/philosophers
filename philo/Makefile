# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 23:18:19 by ramhouch          #+#    #+#              #
#    Updated: 2023/01/23 02:29:57 by ramhouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME=philo
CFLAGS=-Wall -Wextra -Werror
SRC = main.c atoi.c help.c routine.c time.c die.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		cc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ) $(BONUS_OBJ)
fclean: clean
		rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: clean all fclean re