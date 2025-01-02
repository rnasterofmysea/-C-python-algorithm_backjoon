/*
BOj_15650_N과M(2)
https://www.acmicpc.net/problem/15650
*/
#include <stdio.h>

int M, N;
int visited[8];
int arry[8];

void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", arry[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            // 현재 숫자가 이전에 선택된 숫자보다 작으면 제외
            if (depth > 0 && arry[depth - 1] > i + 1) {
                continue;
            }

            arry[depth] = i + 1;
            visited[i] = 1;
            dfs(depth + 1);
            visited[i] = 0; // 백트래킹
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    dfs(0);
    return 0;
}
