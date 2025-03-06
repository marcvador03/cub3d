#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} t_pos;

bool is_open_map(char **map, int rows, int cols) {
    // Create a temporary array to mark visited cells
    bool **visited = (bool **)malloc(rows * sizeof(bool *));
    for (int i = 0; i < rows; i++) {
        visited[i] = (bool *)malloc(cols * sizeof(bool));
        memset(visited[i], false, cols * sizeof(bool));
    }

    // Directions for moving up, down, left, right
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Find a starting point (an empty space)
    t_pos start = {-1, -1};
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W') {
                start.x = x;
                start.y = y;
                break;
            }
        }
        if (start.x != -1) break;
    }

    if (start.x == -1) return false; // No empty space found

    // Use a stack for DFS
    t_pos stack[rows * cols];
    int top = -1;
    stack[++top] = start;
    visited[start.y][start.x] = true;

    while (top >= 0) {
        t_pos current = stack[top--];

        // Check if we are at the boundary
        if (current.x == 0 || current.x == cols - 1 || current.y == 0 || current.y == rows - 1) {
            // Free memory
            for (int i = 0; i < rows; i++) free(visited[i]);
            free(visited);
            return true; // Map is open
        }

        // Explore neighbors
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dir[i][0];
            int ny = current.y + dir[i][1];

            if (nx >= 0 && nx < cols && ny >= 0 && ny < rows && !visited[ny][nx] && (map[ny][nx] == '0' || map[ny][nx] == 'N' || map[ny][nx] == 'S' || map[ny][nx] == 'E' || map[ny][nx] == 'W')) {
                stack[++top] = (t_pos){nx, ny};
                visited[ny][nx] = true;
            }
        }
    }

    // Free memory
    for (int i = 0; i < rows; i++) free(visited[i]);
    free(visited);

    return false; // Map is closed
}
