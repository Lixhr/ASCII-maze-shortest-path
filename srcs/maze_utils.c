#include "../includes/maze.h"

void	print_maze(t_maze *maze)
{
	for (int row = 0; row <= maze->height ; row ++)
	{
		printf("%s\n", maze->str[row]);
	}
	printf("\n");
}
