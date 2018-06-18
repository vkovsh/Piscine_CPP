# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 11:56:39 by vkovsh            #+#    #+#              #
#    Updated: 2018/06/18 11:56:44 by vkovsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook

SRCS	=	phonebook.cpp		\
			ContactClass.cpp
			
FLAGS	=	-Wall -Werror -Wextra
CC		=	clang++
RM		=	rm -rf

OBJ		=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
			@echo "Compiling" [ $(NAME) ]

%.o:		%.cpp
			@$(CC) -o $@ -c $< $(FLAGS)
			@echo "Linking" [ $< ]

clean:
			@$(RM) $(OBJ)
			@echo "Cleaning" [ $(OBJ) ]

fclean:		clean
			@$(RM) $(NAME)
			@echo "Cleaning" [ $(NAME) ]

re:			fclean all

.PHONY:		re fclean clean all
