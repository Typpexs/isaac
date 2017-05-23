CC 				= clang++

RM 				= rm -f

NAME			= maze

SRCS			= main.cpp \
				  Room.cpp \
				  Floor.cpp \
				  Wall.cpp \
				  AObject.cpp

CFLAGS 			+= -Wextra -Wall

OBJS			= $(SRCS:.cpp=.o)

$(NAME): 		$(OBJS)
				$(CC) -o $(NAME) $(OBJS)

all: 			$(NAME)

clean:
				$(RM) $(OBJS)

fclean: 		clean
				$(RM) $(NAME)

re: 			fclean all