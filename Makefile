CC 				= clang++

RM 				= rm -f

NAME			= maze

SRCS			= main.cpp \
				  Room.cpp \
				  Floor.cpp \
				  Wall.cpp \
				  AObject.cpp \
				  Maze.cpp \
				  Dors.cpp

CFLAGS 			+= -Wextra -Wall

OBJS			= $(SRCS:.cpp=.o)

$(NAME): 		$(OBJS)
				$(CC) -std=c++11 -o $(NAME) $(OBJS) $(CFLAGS)

all: 			$(NAME)

clean:
				$(RM) $(OBJS)

fclean: 		clean
				$(RM) $(NAME)

re: 			fclean all