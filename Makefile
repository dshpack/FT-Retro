NAME = ft_retro

FLAGS = -Wall -Wextra -Werror

SRCS =	main.cpp\
        BadGuys.cpp\
        pairMy.cpp\
        WinFrame.cpp\
        Game.cpp\
        Bullets.cpp\
        SpaceOnBack.cpp\
        Players.cpp

INC	 =	pairMy.h\
        BadGuys.h\
        WinFrame.h\
        Game.h\
        AObject.h\
        Bullets.h\
        SpaceOnBack.hpp\
        Players.h

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Building of $(NAME)..."
	@clang++ -o $(NAME) $(OBJ) -lncurses

%.o: %.cpp $(INC)
	clang++ $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all