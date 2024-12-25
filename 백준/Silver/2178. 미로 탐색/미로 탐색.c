///////////////////////////////////////////////////////////////
/*
2번 코드
https://www.acmicpc.net/problem/2178
[BOJ 2178] 미로탐색
KEYPOINT: x,y 방향
*/


#include <stdio.h>
#include <stdlib.h>

// 전역 변수 선언
int *graph;
int queue[10001][2];
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
    enqueue(0, 0);        // 시작점 (0, 0) 삽입

    while (front < rear) { // 큐가 비어있지 않을 때
        int x, y;
        dequeue(&x, &y);

        // 상하좌우 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            // 유효 범위 확인 및 이동 가능 여부 체크
            if (0 <= nx && nx < N && 0 <= ny && ny < M && graph[nx * M + ny] == 1) {
                graph[nx * M + ny] = graph[x * M + y] + 1;  // 거리 갱신
                enqueue(nx, ny);
            }
        }
    }

    // 도착지 (N-1, M-1)의 값 반환
    return graph[(N - 1) * M + (M - 1)];
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // 그래프 및 큐 초기화
    graph = (int *)malloc(N * M * sizeof(int));

    // 그래프 입력
    for (int i = 0; i < N; i++) {
        char line[M + 1];
        scanf("%s", line);
        for (int j = 0; j < M; j++) {
            graph[i * M + j] = line[j] - '0';  // 문자 -> 정수 변환
        }
    }

    // BFS 실행 및 결과 출력
    printf("%d\n", bfs(N, M));

    // 메모리 해제
    free(graph);

    return 0;
}