#include <stdio.h>
#include <stdlib.h>

// 전역 변수 선언
int *graph;
int *visited;
int *queue;
int front = -1, rear = -1;

// 큐에 값 삽입
void enqueue(int num) {
    queue[++rear] = num;
}

// 큐에서 값 제거
int dequeue() {
    return queue[++front];
}

// DFS 함수
void dfs(int node, int num_node) {
    printf("%d ", node + 1);  // 1-based 출력
    visited[node] = 1;        // 방문 처리

    for (int i = 0; i < num_node; i++) {
        if (!visited[i] && graph[node * num_node + i]) {
            dfs(i, num_node);  // 연결된 노드로 이동
        }
    }
}

// BFS 함수
void bfs(int start, int num_node) {
    enqueue(start);
    visited[start] = 1;

    while (front != rear) {  // 큐가 비어 있지 않을 때까지 반복
        int current = dequeue();
        printf("%d ", current + 1);  // 1-based 출력

        for (int i = 0; i < num_node; i++) {
            if (!visited[i] && graph[current * num_node + i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int N, M, V;

    // 노드 수, 간선 수, 시작 노드 입력
    scanf("%d %d %d", &N, &M, &V);

    // 동적 메모리 할당
    graph = (int *)malloc(N * N * sizeof(int));  // 인접 행렬
    visited = (int *)malloc(N * sizeof(int));
    queue = (int *)malloc(N * sizeof(int));

    // 초기화
    for (int i = 0; i < N * N; i++) {
        graph[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }

    // 간선 입력 (양방향 그래프)
    for (int i = 0; i < M; i++) {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        num1--;  // 1-based -> 0-based 변환
        num2--;
        graph[num1 * N + num2] = 1;
        graph[num2 * N + num1] = 1;  // 양방향 처리
    }

    // DFS 실행
    dfs(V - 1, N);
    printf("\n");

    // 방문 배열 초기화
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }

    // BFS 실행
    front = rear = -1;  // 큐 초기화
    bfs(V - 1, N);

    // 메모리 해제
    free(graph);
    free(visited);
    free(queue);

    return 0;
}
