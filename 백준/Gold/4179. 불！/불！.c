#include <stdio.h>
#include <stdlib.h>

#define INF 1000000

// 전역 변수 선언
char graph[1000][1000];
int j_visited[1000][1000];
int f_visited[1000][1000];
int j_queue[1000000][2];
int f_queue[1000000][2];
int j_front = 0, j_rear = 0;
int f_front = 0, f_rear = 0;
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

// 큐 삽입
void enqueue(int queue[][2], int *rear, int x, int y) {
    queue[*rear][0] = x;
    queue[*rear][1] = y;
    (*rear)++;
}

// 큐 제거
void dequeue(int queue[][2], int *front, int *x, int *y) {
    *x = queue[*front][0];
    *y = queue[*front][1];
    (*front)++;
}

// 불의 BFS
void fire_bfs(int R, int C) {
    while (f_front < f_rear) {
        int x, y;
        dequeue(f_queue, &f_front, &x, &y);

        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if (nx >= 0 && nx < R && ny >= 0 && ny < C && graph[nx][ny] == '.' && f_visited[nx][ny] == 0) {
                f_visited[nx][ny] = f_visited[x][y] + 1;
                enqueue(f_queue, &f_rear, nx, ny);
            }
        }
    }
}

// 지훈이의 BFS
int jihun_bfs(int R, int C) {
    while (j_front < j_rear) {
        int x, y;
        dequeue(j_queue, &j_front, &x, &y);

        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            // 탈출 조건
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                return j_visited[x][y];
            }

            // 이동 조건
            if (graph[nx][ny] == '.' && j_visited[nx][ny] == 0 && (f_visited[nx][ny] == 0 || j_visited[x][y] + 1 < f_visited[nx][ny])) {
                j_visited[nx][ny] = j_visited[x][y] + 1;
                enqueue(j_queue, &j_rear, nx, ny);
            }
        }
    }

    return -1; // 탈출 불가능
}

int main() {
    int R, C;
    scanf("%d %d", &R, &C);

    // 입력 및 초기화
    for (int i = 0; i < R; i++) {
        scanf("%s", graph[i]);
        for (int j = 0; j < C; j++) {
            if (graph[i][j] == 'J') {
                enqueue(j_queue, &j_rear, i, j);
                j_visited[i][j] = 1;
            }
            if (graph[i][j] == 'F') {
                enqueue(f_queue, &f_rear, i, j);
                f_visited[i][j] = 1;
            }
        }
    }

    // BFS 실행
    fire_bfs(R, C);
    int result = jihun_bfs(R, C);

    if (result == -1) {
        printf("IMPOSSIBLE\n");
    } else {
        printf("%d\n", result);
    }

    return 0;
}
