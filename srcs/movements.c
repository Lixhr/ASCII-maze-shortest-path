#include "../includes/maze.h"



t_point	*create_new_point(int x, int y)
{
	t_point	*new_point;

	new_point = NULL;
	new_point = (t_point *) malloc(sizeof(t_point));
	if (new_point == NULL)
	{
		fprintf(stderr, "Failed to allocate memory...");
		return (NULL);
	}
	new_point->x = x;
	new_point->y = y;
	return (new_point);
}

int	is_char_wall(t_maze *maze, char c)
{
	return(c == maze->walls);
}

int	is_point_ending(t_maze *maze, t_point *point)
{
	return (maze->str[point->y][point->x] == 'E');
}

void initQueue(Queue *q) 
{
    q->front = q->rear = 0;
}

int isEmpty(Queue *q) 
{
    return (q->front == q->rear);
}

void enqueue(Queue *q, t_point point, int distance) 
{
    q->nodes[q->rear].point = point;
    q->nodes[q->rear].distance = distance;
    q->rear++;
}

QueueNode dequeue(Queue *q) 
{
    return (q->nodes[q->front++]);
}

int is_valid_move(t_maze *maze, int x, int y, int visited[MAX_ROWS][MAX_COLS]) 
{
    return (x >= 0 && x <= maze->width && y >= 0 && y <= maze->height &&
            !is_char_wall(maze, maze->str[y][x]) && !visited[y][x]);
}

void fill_path(t_path *path, t_maze *maze) 
{
    t_point current = path->end;
    t_point path_points[MAX_ROWS * MAX_COLS];
    int path_length = 0;

    while (path->parent[current.y][current.x].x != -1 && path->parent[current.y][current.x].y != -1) 
	{
        path_points[path_length++] = current;
        current = path->parent[current.y][current.x];
    }
    path_points[path_length++] = current;

    for (int i = path_length - 2; i > 0; i--) 
	{
        maze->str[path_points[i].y][path_points[i].x] = '.';
    }
}

int	compare_points(t_point *a, t_point *b)
{
	return (a->x == b->x && a->y == b->y);
}

t_path	*create_new_path()
{
	t_path	*path;

	path = NULL;
	path = (t_path *) malloc(sizeof(t_path));
	if (path == NULL)
	{
		fprintf(stderr, "Failed to allocate memory...");
		return (NULL);
	}
	return (path);
}

t_path	*bfs(t_maze *maze, t_point *point_a, t_point *point_b) 
{
    int visited[MAX_ROWS][MAX_COLS] = {0};
    int rowNum[] = {-1, 0, 0, 1};
    int colNum[] = {0, -1, 1, 0};
	int	row;
	int col;
	t_path	*path;

	path = NULL;
	path = create_new_path();
  	if (path == NULL)
	{
		return (NULL);
	}
	path->distance = 0;
	t_point	parent[MAX_ROWS][MAX_COLS];
    for (int i = 0; i <= maze->height; i++) 
	{
        for (int j = 0; j <= maze->width; j++) 
		{
            parent[i][j].x = -1;
            parent[i][j].y = -1;
        }
    }
    Queue q;
    initQueue(&q);
    enqueue(&q, *point_a, 0);
    visited[point_a->y][point_a->x] = 1;
    while (!isEmpty(&q)) 
	{
        QueueNode current = dequeue(&q);
        t_point pt = current.point;

        if (compare_points(&pt, point_b)) 
		{
			path->distance = current.distance;
 			memcpy(path->parent, parent, sizeof(parent));
			path->end = pt;
            return (path);
        }
        for (int i = 0; i < 4; i++) 
		{
            row = pt.y + rowNum[i];
            col = pt.x + colNum[i];

            if (is_valid_move(maze, col, row, visited)) 
			{
                visited[row][col] = 1;
                parent[row][col] = pt;
                t_point adjacent = {col, row};
                enqueue(&q, adjacent, current.distance + 1);
            }
        }
    }
	path->distance = -1;
    return (path);
}
