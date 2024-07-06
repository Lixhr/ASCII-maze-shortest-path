#ifndef MAZE_H
# define MAZE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

#define	MAX_ROWS 100
#define MAX_COLS 100

typedef struct t_point
{
	int			x;
	int 		y;
} 	t_point;

typedef struct
{
	char 		**str;
	int			height;
	int			width;
	char 		walls;
	t_point 	*starting;
	t_point 	*ending;

}	t_maze;

typedef struct 
{
    t_point 	point;
    int 		distance;
} QueueNode;

typedef struct 
{
    QueueNode 	nodes[MAX_ROWS * MAX_COLS];
    int			front, rear;
} Queue;

typedef struct
{
	int			distance;
    t_point 	parent[MAX_ROWS][MAX_COLS];
    t_point 	end;
} t_path;


//  MOVEMENTS
t_point 		*create_new_point(int x, int y);
int 			is_char_wall(t_maze *maze, char c);
int 			is_point_ending(t_maze *maze, t_point *point);
void 			initQueue(Queue *q);
int 			isEmpty(Queue *q);
void 			enqueue(Queue *q, t_point point, int distance);
QueueNode 		dequeue(Queue *q);
int 			is_valid_move(t_maze *maze, int x, int y, int visited[MAX_ROWS][MAX_COLS]);
t_path 			*bfs(t_maze *maze, t_point *point_a, t_point *point_b);
void 			fill_path(t_path *path, t_maze *maze);
//  GET_MAZE_DATA
char    		**ask_maze_input(void);
int 			get_maze_width(char *maze_str[]);
int 			get_maze_height(char *maze_str[]);
t_point 		*find_char_point(t_maze *maze, char letter);
t_maze  		*get_maze_infos(void);
char			get_walls_char(t_maze *maze);

//  MAZE_UTILS
void			print_maze(t_maze *maze);
int				free_if_null(void *ptr);

// FREE_VALUES

void			free_maze(t_maze *maze);
void			free_path(t_path *path);
#endif
