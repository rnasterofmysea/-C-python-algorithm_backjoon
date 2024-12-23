#include <stdio.h>
#include <stdlib.h>
/*
노드를 입력 받고 노드 수만큼 반복
방문을 하지 않았으면 그래프 탐색(DFS, BFS) 진행
탐색이 끝나면 연결요소 + 1

*/
int *graph;
int *visited;
int *queue;
int front = -1; 
int rear = -1;

void enqueue(int num){
    queue[++rear] = num;
}

int dequeue(){
    return(queue[++front]);
}

void bfs(int start, int num_node){
    enqueue(start);
    visited[start] = 1;
    while(front <= rear){
        int current = dequeue();
        for(int i = 0; i < num_node; i++){
            if(!visited[i] && graph[current * num_node + i]){
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {

    int result = 0; // 연결 요소 갯수 (결과)
    int N, M = 0; // 정점 개수 N, 간선 개수 M
    scanf("%d %d", &N, &M);
    
    visited = (int *)malloc(N * sizeof(int));
    graph = (int *)malloc(N * N * sizeof(int));
    queue = (int *)malloc(N * sizeof(int));
    
    for(int i = 0 ; i < N; i++){
        visited[i] = 0;
    }

    for(int i = 0 ; i < N*N; i++){
        graph[i] = 0;
    }

    
    int u, v = 0;
    for(int i = 0; i < M; i ++){
        scanf("%d %d", &u, &v);
        u--;
        v--;
        graph[u * N + v] = 1;
        graph[v * N + u] = 1;
    }

    for(int i = 0; i < N; i++){
        if(!visited[i]){
            front = -1;
            rear = -1;
            bfs(i, N);
            result++;
        }
    }
    printf("%d", result);
    free(queue);
    free(graph);
    free(visited);
    return 0;
}
