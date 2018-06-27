NAME	=	whatever

SRCS	=	whatever.cpp
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
