#include "../includes/maze.h"

int	main(void)
{
	t_maze	*maze;
	int		distance;
	t_path	*path;


	maze = get_maze_infos();
	if (maze == NULL)
	{
		free_maze(maze);
		exit(EXIT_FAILURE);
	}

	path = NULL;
	path =  bfs(maze, maze->starting, maze->ending);			

    if (path->distance != -1) 
	{
		fill_path(path, maze);
		print_maze(maze);
        printf("shortest path: %d\n", path->distance);
    }
	else 
	{
        fprintf(stderr, "No path found...\n");
    }
	free_path(path);
	free_maze(maze);
}

