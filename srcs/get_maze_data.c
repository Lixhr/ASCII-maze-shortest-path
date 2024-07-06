#include "../includes/maze.h"

int	get_maze_width(char *maze_str[])
{
	int	counter;

	if(maze_str == NULL)
	{
		return (-1);
	}
	counter = 0;
	while (maze_str[0][counter] != '\x00')
	{
		counter ++;	
	}
	return (counter -1);
}

int	get_maze_height(char *maze_str[])
{
	int	counter;

	if (maze_str == NULL)
	{
		return (-1);
	}
	counter = 0;
	while (maze_str[counter] != NULL)
	{
		counter ++;
	}
	return (counter -1);
}

char	**ask_maze_input(void)
{
	char 	**maze = NULL;
	char	buffer[MAX_COLS +1];
	int row;	

	row = 0;
	maze = (char **) malloc(MAX_ROWS * sizeof(char *));
	if (maze == NULL)
	{
		return (NULL);
	}
	fprintf(stdout, "Please paste your ASCII maze (end it with a blank line):\n");
    while (fgets(buffer, MAX_COLS, stdin) != NULL) 
	{
		if (buffer[0] == '\n') 
		{
			if (row == 0)
			{
				fprintf(stderr, "Please enter a maze.\n");
				return (NULL);
			}
            break;
		}
        buffer[strcspn(buffer, "\n")] = 0;
		maze[row] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
		if (maze[row] == NULL)
		{
			return (NULL);
		}
		strcpy(maze[row], buffer);
		row ++;		
	}
	maze[row] = NULL;
	return (maze);	
}

char	get_walls_char(t_maze *maze)
{

	char	possible_char;
	char 	anwser;

	possible_char = maze->str[maze->height/2][0];
	anwser = possible_char;
	printf("Your walls seems to be '%c'.\n", possible_char);
	printf("Type Y to agree, else type your char : ");
	anwser = fgetc(stdin);
	if (anwser == 'Y' || anwser == 'y' || anwser == '\n')
	{
		return (possible_char);
	}
	printf("\n");
	return (anwser);
}

t_maze	*get_maze_infos(void)
{
	t_maze	*maze;

	maze = NULL;
	maze = (t_maze *) malloc(sizeof(t_maze));
	if (maze == NULL)
	{
		fprintf(stderr, "Allocation problem...");
		free_maze(maze);
		return (NULL);
	}
	maze->str = NULL;
	maze->starting = NULL;
	maze->ending = NULL;

	maze->str = ask_maze_input();
	if (maze->str == NULL)
	{
		fprintf(stderr, "There is a problem with your maze...");
		free_maze(maze);
		return (NULL);
	}
	maze->width = get_maze_width(maze->str);	
	maze->height = get_maze_height(maze->str);
	if (maze->width == -1 || maze ->height == -1)
	{
		free_maze(maze);
		return (NULL);
	}
	maze->walls = get_walls_char(maze);
	maze->starting = find_char_point(maze, 'S');
	if (maze->starting == NULL)
	{
		fprintf(stderr, "Please specify a starting point: 'S'");
		free_maze(maze);
		return (NULL);
	}
	maze->ending = find_char_point(maze, 'E');
	if (maze->ending == NULL)
	{
		fprintf(stderr, "Please specify a ending point: 'E'");
		free_maze(maze);
		return (NULL);
	}
	return (maze);
}

t_point	*find_char_point(t_maze *maze, char letter)
{
	t_point	*char_point;
	int x;

	char_point = NULL;

	for (int y = 0; y <= maze->height; y ++)
	{
		x = 0;
		while (maze->str[y][x] != '\x00')
		{
			if (maze->str[y][x] == letter)
			{
				char_point = (t_point *) malloc(sizeof(t_point));
				if (char_point == NULL)
				{
					free(char_point);
					return (NULL);
				}
				char_point->x = x;	
				char_point->y = y;
				return (char_point);	
			}
			x++;
		}
	}
	return (NULL);
}
