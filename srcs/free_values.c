#include "../includes/maze.h"

void	free_maze(t_maze *maze)
{
	if (maze)
	{
		if (maze->starting)
		{
			free(maze->starting);
		}
		if (maze->ending)
		{
			free(maze->ending);
		}
		if (maze->str)
		{
			for (int height = 0; height <= maze->height; height++)
			{
				if (maze->str[height])
				{
					free(maze->str[height]);
				}
			}
			free(maze->str);
		}
		free(maze);
	}
}

void	free_path(t_path *path)
{
	if (path)
	{
		free(path);
	}
}
