/*
N과 M (1)
https://www.acmicpc.net/problem/15649
*/

#include <stdio.h>

int N, M;
int arr[8]; // 순열을 저장할 배열
int visited[9]; // 방문 여부를 체크할 배열

void dfs(int depth) {
    if (depth == M) { // M개의 숫자를 모두 선택한 경우
        for (int i = 0; i < M; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) { // 아직 방문하지 않은 숫자인 경우
            visited[i] = 1; // 방문 표시
            arr[depth] = i; // 순열 배열에 추가
            dfs(depth + 1); // 다음 숫자 선택
            visited[i] = 0; // 백트래킹: 방문 표시 해제
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    dfs(0); // DFS 시작
    return 0;
}