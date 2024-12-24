/*
https://www.acmicpc.net/problem/2178
[BOJ 2178] 미로탐색
KEYPOINT: x,y 방향
*/


#include <stdio.h>
#include <stdlib.h>

// 전역 변수 선언
int graph[100][100];
int queue[10000][2];
int front = 0;
int rear = 0;

// 상하좌우 이동 방향 (x, y)
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

// 큐 삽입
void enqueue(int x, int y) {
    queue[rear][0] = x;
    queue[rear][1] = y;
    rear++;
}

// 큐 제거
void dequeue(int *x, int *y) {
    *x = queue[front][0];
    *y = queue[front][1];
    front++;
}

// BFS
int bfs(int N, int M) {
    enqueue(0, 0);        // 시작점 삽입
    graph[0][0] = 1;      // 시작점 거리 초기화

    while (front < rear) { // 큐가 비어있지 않을 때
        int x, y;
        dequeue(&x, &y);

        // 상하좌우 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            // 유효 범위 및 이동 가능 여부 확인
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && graph[nx][ny] == 1) {
                graph[nx][ny] = graph[x][y] + 1;  // 거리 갱신
                enqueue(nx, ny);
            }
        }
    }

    // 도착점 거리 반환
    return graph[N - 1][M - 1];
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // 미로 입력
    for (int i = 0; i < N; i++) {
        char line[M + 1];
        scanf("%s", line);
        for (int j = 0; j < M; j++) {
            graph[i][j] = line[j] - '0';  // 문자 -> 정수 변환
        }
    }

    // BFS 실행 및 결과 출력
    printf("%d\n", bfs(N, M));
    return 0;
}
