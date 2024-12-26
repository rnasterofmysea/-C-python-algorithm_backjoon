#include <stdio.h>
#include <stdlib.h>

// 전역 변수 선언
int graph[1000][1000];
int visited[1000000];
int queue[1000001][2];
int front = 0;
int rear = 0;
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

// BFS 함수
int bfs(int m, int n) {
    int max_distance = 0;

    while (front < rear) { // 큐가 비어있지 않을 동안
        int x, y;
        dequeue(&x, &y);
        visited[y * m + x] = 1;

        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            // 유효 범위 및 방문 여부 확인
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && visited[ny * m + nx] == 0 && graph[ny][nx] == 0) {
                visited[ny * m + nx] = 1; // 방문 처리
                graph[ny][nx] = graph[y][x] + 1; // 거리 갱신
                enqueue(nx, ny);
                if (graph[ny][nx] > max_distance) {
                    max_distance = graph[ny][nx];
                }
            }
        }
    }
    if (max_distance == 0){return 0;} else{
        return max_distance - 1; // 시작점을 포함하므로 1을 뺌
    }
}

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    // 그래프 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &graph[i][j]);
            visited[i * M + j] = 0; // 방문 초기화
            if(graph[i][j] == 1){
                enqueue(j, i);
            }
        }
    }

    // BFS 실행 및 결과 계산
    int max = 0;
    max = bfs(M, N);

    // 0이면서 방문되지 않은 노드가 있으면 -1 출력
    int flag = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 0 && visited[i * M + j] == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) break;
    }

    if (flag == 1) {
        
        printf("-1");
    } else {
        printf("%d", max);
    }

    return 0;
}
