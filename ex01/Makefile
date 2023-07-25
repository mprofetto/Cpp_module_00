# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/22 10:54:57 by mprofett          #+#    #+#              #
#    Updated: 2023/07/25 15:25:38 by mprofett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= phonebook

SRC			= Contact.cpp PhoneBook.cpp PhoneBookUtils.cpp main.cpp

OBJ			= ${SRC:.cpp=.o}

CC			= g++

RM			= rm -rf

C_FLAGS	= -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${C_FLAGS} ${OBJ} -o ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
