/*
C_BOJ_18869_멀티버스 II 
https://www.acmicpc.net/problem/18869
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int is_same_universe(int *u1, int *u2, int N) {
    for (int i = 0; i < N; i++) {
        if (u1[i] != u2[i]) {
            return 0;  // 두 배열이 다름
        }
    }
    return 1;  // 두 배열이 같음
}

int main() {
    int M, N;
    int universe[100][10000];
    int copy_universe[100][10000];

    scanf("%d %d", &M, &N);

    // 입력 받기
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &universe[i][j]);
            copy_universe[i][j] = universe[i][j];
        }
    }

    // 각 우주의 상대적 순위 계산
    for (int i = 0; i < M; i++) {
        qsort(copy_universe[i], N, sizeof(int), compare);

        for (int j = 0; j < N; j++) {
            int target = universe[i][j];
            int start = 0, end = N - 1;

            // 이진 탐색으로 상대적 순위 찾기
            while (start <= end) {
                int mid = start + (end - start) / 2;
                if (copy_universe[i][mid] == target) {
                    universe[i][j] = mid;
                    break;
                } else if (copy_universe[i][mid] < target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
    }

    // 우주 간 비교 작업
    int count = 0;
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            if (is_same_universe(universe[i], universe[j], N)) {
                count++;
            }
        }
    }

    // 결과 출력
    printf("%d\n", count);

    return 0;
}
