PROGRAM_NAME = shortest_path
SRCS = 	./srcs/main.c \
		./srcs/maze_utils.c\
		./srcs/get_maze_data.c\
		./srcs/free_values.c\
		./srcs/movements.c

OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	gcc -o $(PROGRAM_NAME) $(OBJS)

test: $(PROGRAM_NAME)
	./test.exp

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f ./$(PROGRAM_NAME)

.PHONY : all clean fclean test
