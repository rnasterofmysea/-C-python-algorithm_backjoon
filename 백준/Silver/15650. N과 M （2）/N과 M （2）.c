#include <stdio.h>

int M, N;
int arry[8];

void dfs(int depth, int start) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", arry[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i < N; i++) { // 탐색 시작점을 start로 제한
        arry[depth] = i + 1; // 숫자 저장
        dfs(depth + 1, i + 1); // 다음 단계 탐색, 시작 인덱스를 i+1로 설정
    }
}

int main() {
    scanf("%d %d", &N, &M);
    dfs(0, 0); // depth = 0, start = 0부터 탐색 시작
    return 0;
}
