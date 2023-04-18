#include <stdio.h>
#include <stdlib.h>

#define MAZE_SIZE 10

char maze[MAZE_SIZE][MAZE_SIZE] = {
        {'1','1','1','1','1','1','1','1','1','1'},
        {'e','1','0','1','0','0','0','1','0','1'},
        {'0','0','0','1','0','0','0','1','0','1'},
        {'0','1','0','0','0','1','1','0','0','1'},
        {'1','0','0','0','1','0','0','0','0','1'},
        {'1','0','0','0','1','0','0','0','0','1'},
        {'1','0','0','0','0','0','1','0','1','1'},
        {'1','0','1','1','1','0','1','1','0','1'},
        {'1','1','0','0','0','0','0','0','0','x'},
        {'1','1','1','1','1','1','1','1','1','1'}
};

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point point;
    int direction;
} Move;

typedef struct {
    Point point;
    int direction;
} Element;

void print_maze() {
    int i, j;
    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(Point point) {
    if (point.x < 0 || point.x >= MAZE_SIZE || point.y < 0 || point.y >= MAZE_SIZE) {
        return 0;
    }

    if (maze[point.x][point.y] == '1' || maze[point.x][point.y] == '.') {
        return 0;
    }
    return 1;
}

void mark_visited(Point point) {
    maze[point.x][point.y] = '.';
}

int dfs(Point start, Point end) {
    Move moves[] = { { {-1, 0}, 1 }, { {0, 1}, 2 }, { {1, 0}, 3 }, { {0, -1}, 4 } };
    Element stack[MAZE_SIZE * MAZE_SIZE];
    int top = -1;
    Element current = { start, 0 };
    stack[++top] = current;
    int visited[MAZE_SIZE][MAZE_SIZE] = {0};

    while (top >= 0) {
        current = stack[top--];
        Point point = current.point;
        int direction = current.direction;

        if (point.x == end.x && point.y == end.y) {
            return top + 1;
        }

        visited[point.x][point.y] = 1;

        int i;
        for (i = 0; i < 4; i++) {
            Point new_point = { point.x + moves[i].point.x, point.y + moves[i].point.y };
            int new_direction = moves[i].direction;

            if (is_valid_move(new_point) && visited[new_point.x][new_point.y] == 0) {
                Element new_element = { new_point, new_direction };
                stack[++top] = new_element;
                visited[new_point.x][new_point.y] = 1;
                maze[new_point.x][new_point.y] = '.';
            }
        }
    }
    return -1;
}

void print_path(Element* path, int length) {
    int i;
    for (i = length - 1; i >= 0; i--) {
        printf("(%d, %d) ", path[i].point.x, path[i].point.y);
    }
    printf("\n");
}

int dfs_with_path(Point start, Point end, Element* path) {
    Move moves[] = { { {-1, 0}, 1 }, { {0, 1}, 2 }, { {1, 0}, 3 }, { {0, -1}, 4 } };
    Element stack[MAZE_SIZE * MAZE_SIZE];
    int top = -1;
    Element current = { start, 0 };
    stack[++top] = current;
    int visited[MAZE_SIZE][MAZE_SIZE] = {0};
    int path_length = 0;

    while (top >= 0) {
        current = stack[top--];
        Point point = current.point;
        int direction = current.direction;

        if (point.x == end.x && point.y == end.y) {
            int i;
            for (i = 0; i <= top; i++) {
                path[i] = stack[i];
            }
            path_length = top + 1;
            break;
        }

        visited[point.x][point.y] = 1;

        int i;
        for (i = 0; i < 4; i++) {
            Point new_point = { point.x + moves[i].point.x, point.y + moves[i].point.y };
            int new_direction = moves[i].direction;

            if (is_valid_move(new_point) && visited[new_point.x][new_point.y] == 0) {
                Element new_element = { new_point, new_direction };
                stack[++top] = new_element;
                visited[new_point.x][new_point.y] = 1;
                maze[new_point.x][new_point.y] = '.';
            }
        }
    }
    return path_length;
}


int main() {
    Point start = { 1, 0 };
    Point end = { 8, 9 };
    Element path[MAZE_SIZE * MAZE_SIZE];
    print_maze();
    int path_length = dfs_with_path(start, end, path);
    if (path_length > 0) {
        printf("-------------------\n");
        print_maze();
        printf("-------------------\n");
        printf("Back count : %d\n", path_length);
        printf("Path : ");
        print_path(path, path_length);
    } else {
        printf("\n no find path.\n");
    }
    return 0;
}
