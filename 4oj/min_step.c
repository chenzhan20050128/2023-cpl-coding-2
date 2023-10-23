#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10000

typedef struct {
    int x;
    int y;
    int steps;
    char path[MAX_QUEUE_SIZE];
} Node;

int isOccupied(int x, int y, int xC, int yC) {
    return (x == xC && y == yC);
}

int isInRange(int x, int y, int xA, int yA, int xB, int yB) {
    return (x >= xA && x <= xB && y >= yA && y <= yB);
}

int bfs(int xA, int yA, int xB, int yB, int xC, int yC, int *minSteps, char *path) {
    int visited[MAX_QUEUE_SIZE][MAX_QUEUE_SIZE];
    memset(visited, 0, sizeof(visited));

    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};
    char directions[] = {'U', 'D', 'L', 'R'};

    Node queue[MAX_QUEUE_SIZE];
    int front = 0, rear = 0;

    Node start;
    start.x = xA;
    start.y = yA;
    start.steps = 0;
    strcpy(start.path, "");
    queue[rear++] = start;
    visited[xA][yA] = 1;

    while (front < rear) {
        Node cur = queue[front++];
        if (cur.x == xB && cur.y == yB) {
            *minSteps = cur.steps;
            strcpy(path, cur.path);
            return 1;
        }

        for (int i = 0; i < 4; i++) {
            int newX = cur.x + dx[i];
            int newY = cur.y + dy[i];
            if (isInRange(newX, newY, xA, yA, xB, yB) && !isOccupied(newX, newY, xC, yC) && !visited[newX][newY]) {
                Node next;
                next.x = newX;
                next.y = newY;
                next.steps = cur.steps + 1;
                strcpy(next.path, cur.path);
                next.path[next.steps - 1] = directions[i];
                next.path[next.steps] = '\0';
                queue[rear++] = next;
                visited[newX][newY] = 1;
            }
        }
    }

    return 0;
}

int main() {
    int xA, yA, xB, yB, xC, yC;
    scanf("%d %d %d %d %d %d", &xA, &yA, &xB, &yB, &xC, &yC);

    int minSteps;
    char path[MAX_QUEUE_SIZE];

    if (bfs(xA, yA, xB, yB, xC, yC, &minSteps, path)) {
        printf("%d\n%s\n", minSteps, path);
    } else {
        printf("No path found.\n");
    }

    return 0;
}