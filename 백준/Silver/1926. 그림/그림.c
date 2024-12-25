/*
https://www.acmicpc.net/problem/1926
BOJ 1926

<Keypoint>
BFS + 최단경로 찾기 & 연결요소


연결요소로 각 그림 단위로 분할해서 처리
최단경로 찾기로 그림의 넓이 구하기
*/
#include <stdio.h>

int graph[500][500];
int visited[500][500];
int queue[250000][2];
int front, rear;

// 방향벡터: 상, 하, 좌, 우
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// 큐에 추가
void enqueue(int x, int y) {
    queue[rear][0] = x;
    queue[rear][1] = y;
    rear++;
}

// 큐에서 제거
void dequeue(int *x, int *y) {
    *x = queue[front][0];
    *y = queue[front][1];
    front++;
}

// BFS 함수
int bfs(int start_x, int start_y, int n, int m) {
    int area = 0;
    enqueue(start_x, start_y);
    visited[start_y][start_x] = 1;

    while (front < rear) {
        int x, y;
        dequeue(&x, &y);
        area++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[ny][nx] && graph[ny][nx] == 1) {
                enqueue(nx, ny);
                visited[ny][nx] = 1;
            }
        }
    }

    return area;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // 그래프 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int max_area = 0;
    int count = 0;

    // 전체 그래프 탐색
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                front = rear = 0; // 큐 초기화
                int area = bfs(j, i, n, m);
                if (area > max_area) {
                    max_area = area;
                }
                count++;
            }
        }
    }

    printf("%d\n%d", count, max_area);
    return 0;
}
