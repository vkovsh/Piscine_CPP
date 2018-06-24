NAME	=	ft_retro

SRCS	=	main.cpp		\
			Window.cpp		\
			FieldWindow.cpp	\
			Enemy.cpp		\
			GameEntity.cpp	\
			Player.cpp
			
FLAGS	=	-Wall -Werror -Wextra -g
CC		=	clang++
RM		=	rm -rf

OBJ		=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(FLAGS) $(OBJ) -o $(NAME) -lncurses
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
