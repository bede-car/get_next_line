# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 23:44:16 by bede-car          #+#    #+#              #
#    Updated: 2022/07/19 16:42:04 by bede-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	get_next_line.c get_next_line_utils.c main_get_next_line.c

FILESBONUS	= get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ		= $(FILES:.c=.o) 

OBJBONUS	= $(FILESBONUS:.c=.o) 

CFLAG	= -Wall -Werror -Wextra -g -D BUFFER_SIZE=42

HEADER	= get_next_line.h

NAME	= get_next_line

all : $(NAME)

val : 
	valgrind --show-leak-kinds=all --leak-check=full --log-file=val_log ./$(NAME) 
	
$(NAME) : ${FILES}
	cc ${CFLAG} $^ -o $(NAME) 
	
clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all

bonus :	${FILESBONUS}
	@make OBJ="${OBJ} ${OBJBONUS}" all

.PHONY:	all clean fclean re